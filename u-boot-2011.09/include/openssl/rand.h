/*
 * include/openssl/rand.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */


#ifndef HEADER_RAND_H
#define HEADER_RAND_H


#include "ossl_typ.h"
#include "e_os2.h"

#if 0
#if defined(OPENSSL_SYS_WINDOWS)
#include <windows.h>
#endif
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(OPENSSL_FIPS)
#define FIPS_RAND_SIZE_T int
#endif

/* Already defined in ossl_typ.h */
/* typedef struct rand_meth_st RAND_METHOD; */

struct rand_meth_st
	{
	void (*seed)(const void *buf, int num);
	int (*bytes)(unsigned char *buf, int num);
	void (*cleanup)(void);
	void (*add)(const void *buf, int num, double entropy);
	int (*pseudorand)(unsigned char *buf, int num);
	int (*status)(void);
	};

#ifdef BN_DEBUG
extern int rand_predictable;
#endif

int RAND_set_rand_method(const RAND_METHOD *meth);
const RAND_METHOD *RAND_get_rand_method(void);
#ifndef OPENSSL_NO_ENGINE
int RAND_set_rand_engine(ENGINE *engine);
#endif
RAND_METHOD *RAND_SSLeay(void);
void RAND_cleanup(void );
int  RAND_bytes(unsigned char *buf,int num);
int  RAND_pseudo_bytes(unsigned char *buf,int num);
void RAND_seed(const void *buf,int num);
void RAND_add(const void *buf,int num,double entropy);
int  RAND_load_file(const char *file,long max_bytes);
int  RAND_write_file(const char *file);
const char *RAND_file_name(char *file,size_t num);
int RAND_status(void);
int RAND_query_egd_bytes(const char *path, unsigned char *buf, int bytes);
int RAND_egd(const char *path);
int RAND_egd_bytes(const char *path,int bytes);
int RAND_poll(void);
#ifndef OPENSSL_NO_ENGINE
#ifdef OPENSSL_FIPS
void int_RAND_init_engine_callbacks(void);
void int_RAND_set_callbacks(
	int (*set_rand_func)(const RAND_METHOD *meth,
						const RAND_METHOD **pmeth),
	const RAND_METHOD *(*get_rand_func)(const RAND_METHOD **pmeth));
#endif
#endif

#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)

void RAND_screen(void);
//int RAND_event(UINT, WPARAM, LPARAM);

#endif

/* BEGIN ERROR CODES */
/* The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */
void ERR_load_RAND_strings(void);

/* Error codes for the RAND functions. */

/* Function codes. */
#define RAND_F_ENG_RAND_GET_RAND_METHOD			 108
#define RAND_F_FIPS_RAND				 103
#define RAND_F_FIPS_RAND_BYTES				 102
#define RAND_F_FIPS_RAND_GET_RAND_METHOD		 109
#define RAND_F_FIPS_RAND_SET_DT				 106
#define RAND_F_FIPS_SET_DT				 104
#define RAND_F_FIPS_SET_PRNG_SEED			 107
#define RAND_F_FIPS_SET_TEST_MODE			 105
#define RAND_F_RAND_GET_RAND_METHOD			 101
#define RAND_F_SSLEAY_RAND_BYTES			 100

/* Reason codes. */
#define RAND_R_NON_FIPS_METHOD				 105
#define RAND_R_NOT_IN_TEST_MODE				 106
#define RAND_R_NO_KEY_SET				 107
#define RAND_R_PRNG_ASKING_FOR_TOO_MUCH			 101
#define RAND_R_PRNG_ERROR				 108
#define RAND_R_PRNG_KEYED				 109
#define RAND_R_PRNG_NOT_REKEYED				 102
#define RAND_R_PRNG_NOT_RESEEDED			 103
#define RAND_R_PRNG_NOT_SEEDED				 100
#define RAND_R_PRNG_SEED_MUST_NOT_MATCH_KEY		 110
#define RAND_R_PRNG_STUCK				 104

#ifdef  __cplusplus
}
#endif
#endif
