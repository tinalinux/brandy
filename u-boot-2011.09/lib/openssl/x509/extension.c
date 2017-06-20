/*
 * lib/openssl/x509/extension.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include"x509.h"
#include"stack.h"
#include"x509v3.h"
#include"err.h"
#include"myfunction.h"

#define sk_X509_EXTENSION_value(st, i) SKM_sk_value(X509_EXTENSION, (st), (i))
#define sk_X509_EXTENSION_num(st) SKM_sk_num(X509_EXTENSION, (st))

////////////sk_num//////////////////////////////////ok

int sk_num(const STACK *st)
{

	if(st == NULL) return -1;
	return st->num;
}
//////////sk_value//////////////////////////////ok

char *sk_value(const STACK *st, int i)
{

	if(!st || (i < 0) || (i >= st->num)) return NULL;
	return st->data[i];
}
/////////X509v3_get_ext_count//////////////////////////////ok


