/*
 * lib/openssl/include/openssl/ui.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */


#ifndef HEADER_UI_H
#define HEADER_UI_H

#ifndef OPENSSL_NO_DEPRECATED
#include "crypto.h"
#endif
#include "safestack.h"
#include "ossl_typ.h"

#ifdef  __cplusplus
extern "C" {
#endif


UI *UI_new(void);
UI *UI_new_method(const UI_METHOD *method);
void UI_free(UI *ui);


int UI_add_input_string(UI *ui, const char *prompt, int flags,
	char *result_buf, int minsize, int maxsize);
int UI_dup_input_string(UI *ui, const char *prompt, int flags,
	char *result_buf, int minsize, int maxsize);
int UI_add_verify_string(UI *ui, const char *prompt, int flags,
	char *result_buf, int minsize, int maxsize, const char *test_buf);
int UI_dup_verify_string(UI *ui, const char *prompt, int flags,
	char *result_buf, int minsize, int maxsize, const char *test_buf);
int UI_add_input_boolean(UI *ui, const char *prompt, const char *action_desc,
	const char *ok_chars, const char *cancel_chars,
	int flags, char *result_buf);
int UI_dup_input_boolean(UI *ui, const char *prompt, const char *action_desc,
	const char *ok_chars, const char *cancel_chars,
	int flags, char *result_buf);
int UI_add_info_string(UI *ui, const char *text);
int UI_dup_info_string(UI *ui, const char *text);
int UI_add_error_string(UI *ui, const char *text);
int UI_dup_error_string(UI *ui, const char *text);

/* These are the possible flags.  They can be or'ed together. */
/* Use to have echoing of input */
#define UI_INPUT_FLAG_ECHO		0x01
/* Use a default password.  Where that password is found is completely
   up to the application, it might for example be in the user data set
   with UI_add_user_data().  It is not recommended to have more than
   one input in each UI being marked with this flag, or the application
   might get confused. */
#define UI_INPUT_FLAG_DEFAULT_PWD	0x02

/* The user of these routines may want to define flags of their own.  The core
   UI won't look at those, but will pass them on to the method routines.  They
   must use higher bits so they don't get confused with the UI bits above.
   UI_INPUT_FLAG_USER_BASE tells which is the lowest bit to use.  A good
   example of use is this:

	#define MY_UI_FLAG1	(0x01 << UI_INPUT_FLAG_USER_BASE)

*/
#define UI_INPUT_FLAG_USER_BASE	16


/* The following function helps construct a prompt.  object_desc is a
   textual short description of the object, for example "pass phrase",
   and object_name is the name of the object (might be a card name or
   a file name.
   The returned string shall always be allocated on the heap with
   OPENSSL_malloc(), and need to be free'd with OPENSSL_free().

   If the ui_method doesn't contain a pointer to a user-defined prompt
   constructor, a default string is built, looking like this:

	"Enter {object_desc} for {object_name}:"

   So, if object_desc has the value "pass phrase" and object_name has
   the value "foo.key", the resulting string is:

	"Enter pass phrase for foo.key:"
*/
char *UI_construct_prompt(UI *ui_method,
	const char *object_desc, const char *object_name);


/* The following function is used to store a pointer to user-specific data.
   Any previous such pointer will be returned and replaced.

   For callback purposes, this function makes a lot more sense than using
   ex_data, since the latter requires that different parts of OpenSSL or
   applications share the same ex_data index.

   Note that the UI_OpenSSL() method completely ignores the user data.
   Other methods may not, however.  */
void *UI_add_user_data(UI *ui, void *user_data);
/* We need a user data retrieving function as well.  */
void *UI_get0_user_data(UI *ui);

/* Return the result associated with a prompt given with the index i. */
const char *UI_get0_result(UI *ui, int i);

/* When all strings have been added, process the whole thing. */
int UI_process(UI *ui);

/* Give a user interface parametrised control commands.  This can be used to
   send down an integer, a data pointer or a function pointer, as well as
   be used to get information from a UI. */
int UI_ctrl(UI *ui, int cmd, long i, void *p, void (*f)(void));

/* The commands */
/* Use UI_CONTROL_PRINT_ERRORS with the value 1 to have UI_process print the
   OpenSSL error stack before printing any info or added error messages and
   before any prompting. */
#define UI_CTRL_PRINT_ERRORS		1
/* Check if a UI_process() is possible to do again with the same instance of
   a user interface.  This makes UI_ctrl() return 1 if it is redoable, and 0
   if not. */
#define UI_CTRL_IS_REDOABLE		2


/* Some methods may use extra data */
#define UI_set_app_data(s,arg)         UI_set_ex_data(s,0,arg)
#define UI_get_app_data(s)             UI_get_ex_data(s,0)
int UI_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
	CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func);
int UI_set_ex_data(UI *r,int idx,void *arg);
void *UI_get_ex_data(UI *r, int idx);

/* Use specific methods instead of the built-in one */
void UI_set_default_method(const UI_METHOD *meth);
const UI_METHOD *UI_get_default_method(void);
const UI_METHOD *UI_get_method(UI *ui);
const UI_METHOD *UI_set_method(UI *ui, const UI_METHOD *meth);

/* The method with all the built-in thingies */
UI_METHOD *UI_OpenSSL(void);


/* ---------- For method writers ---------- */
/* A method contains a number of functions that implement the low level
   of the User Interface.  The functions are:

	an opener	This function starts a session, maybe by opening
			a channel to a tty, or by opening a window.
	a writer	This function is called to write a given string,
			maybe to the tty, maybe as a field label in a
			window.
	a flusher	This function is called to flush everything that
			has been output so far.  It can be used to actually
			display a dialog box after it has been built.
	a reader	This function is called to read a given prompt,
			maybe from the tty, maybe from a field in a
			window.  Note that it's called wth all string
			structures, not only the prompt ones, so it must
			check such things itself.
	a closer	This function closes the session, maybe by closing
			the channel to the tty, or closing the window.

   All these functions are expected to return:

	0	on error.
	1	on success.
	-1	on out-of-band events, for example if some prompting has
		been canceled (by pressing Ctrl-C, for example).  This is
		only checked when returned by the flusher or the reader.

   The way this is used, the opener is first called, then the writer for all
   strings, then the flusher, then the reader for all strings and finally the
   closer.  Note that if you want to prompt from a terminal or other command
   line interface, the best is to have the reader also write the prompts
   instead of having the writer do it.  If you want to prompt from a dialog
   box, the writer can be used to build up the contents of the box, and the
   flusher to actually display the box and run the event loop until all data
   has been given, after which the reader only grabs the given data and puts
   them back into the UI strings.

   All method functions take a UI as argument.  Additionally, the writer and
   the reader take a UI_STRING.
*/

/* The UI_STRING type is the data structure that contains all the needed info
   about a string or a prompt, including test data for a verification prompt.
*/
DECLARE_STACK_OF(UI_STRING)
typedef struct ui_string_st UI_STRING;

/* The different types of strings that are currently supported.
   This is only needed by method authors. */
enum UI_string_types
	{
	UIT_NONE=0,
	UIT_PROMPT,		/* Prompt for a string */
	UIT_VERIFY,		/* Prompt for a string and verify */
	UIT_BOOLEAN,		/* Prompt for a yes/no response */
	UIT_INFO,		/* Send info to the user */
	UIT_ERROR		/* Send an error message to the user */
	};

/* Create and manipulate methods */
UI_METHOD *UI_create_method(char *name);
void UI_destroy_method(UI_METHOD *ui_method);
int UI_method_set_opener(UI_METHOD *method, int (*opener)(UI *ui));
int UI_method_set_writer(UI_METHOD *method, int (*writer)(UI *ui, UI_STRING *uis));
int UI_method_set_flusher(UI_METHOD *method, int (*flusher)(UI *ui));
int UI_method_set_reader(UI_METHOD *method, int (*reader)(UI *ui, UI_STRING *uis));
int UI_method_set_closer(UI_METHOD *method, int (*closer)(UI *ui));
int (*UI_method_get_opener(UI_METHOD *method))(UI*);
int (*UI_method_get_writer(UI_METHOD *method))(UI*,UI_STRING*);
int (*UI_method_get_flusher(UI_METHOD *method))(UI*);
int (*UI_method_get_reader(UI_METHOD *method))(UI*,UI_STRING*);
int (*UI_method_get_closer(UI_METHOD *method))(UI*);

/* The following functions are helpers for method writers to access relevant
   data from a UI_STRING. */

/* Return type of the UI_STRING */
enum UI_string_types UI_get_string_type(UI_STRING *uis);
/* Return input flags of the UI_STRING */
int UI_get_input_flags(UI_STRING *uis);
/* Return the actual string to output (the prompt, info or error) */
const char *UI_get0_output_string(UI_STRING *uis);
/* Return the optional action string to output (the boolean promtp instruction) */
const char *UI_get0_action_string(UI_STRING *uis);
/* Return the result of a prompt */
const char *UI_get0_result_string(UI_STRING *uis);
/* Return the string to test the result against.  Only useful with verifies. */
const char *UI_get0_test_string(UI_STRING *uis);
/* Return the required minimum size of the result */
int UI_get_result_minsize(UI_STRING *uis);
/* Return the required maximum size of the result */
int UI_get_result_maxsize(UI_STRING *uis);
/* Set the result of a UI_STRING. */
int UI_set_result(UI *ui, UI_STRING *uis, const char *result);


/* A couple of popular utility functions */
int UI_UTIL_read_pw_string(char *buf,int length,const char *prompt,int verify);
int UI_UTIL_read_pw(char *buf,char *buff,int size,const char *prompt,int verify);


/* BEGIN ERROR CODES */
/* The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */
void ERR_load_UI_strings(void);

/* Error codes for the UI functions. */

/* Function codes. */
#define UI_F_GENERAL_ALLOCATE_BOOLEAN			 108
#define UI_F_GENERAL_ALLOCATE_PROMPT			 109
#define UI_F_GENERAL_ALLOCATE_STRING			 100
#define UI_F_UI_CTRL					 111
#define UI_F_UI_DUP_ERROR_STRING			 101
#define UI_F_UI_DUP_INFO_STRING				 102
#define UI_F_UI_DUP_INPUT_BOOLEAN			 110
#define UI_F_UI_DUP_INPUT_STRING			 103
#define UI_F_UI_DUP_VERIFY_STRING			 106
#define UI_F_UI_GET0_RESULT				 107
#define UI_F_UI_NEW_METHOD				 104
#define UI_F_UI_SET_RESULT				 105

/* Reason codes. */
#define UI_R_COMMON_OK_AND_CANCEL_CHARACTERS		 104
#define UI_R_INDEX_TOO_LARGE				 102
#define UI_R_INDEX_TOO_SMALL				 103
#define UI_R_NO_RESULT_BUFFER				 105
#define UI_R_RESULT_TOO_LARGE				 100
#define UI_R_RESULT_TOO_SMALL				 101
#define UI_R_UNKNOWN_CONTROL_COMMAND			 106

#ifdef  __cplusplus
}
#endif
#endif
