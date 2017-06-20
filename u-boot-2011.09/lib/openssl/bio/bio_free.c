/*
 * lib/openssl/bio/bio_free.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include "bio.h"
#include "err.h"
#include"myfunction.h"
//////////////BIO_free/////////////////////////ok

int BIO_free(BIO *a)
{
	int i;
	
	if (a == NULL) return(0);

	i=CRYPTO_add(&a->references,-1,CRYPTO_LOCK_BIO);////////samyang 	CRYPTO_add_lock
	if (i > 0) return(1);
	if ((a->callback != NULL) &&
		((i=(int)a->callback(a,BIO_CB_FREE,NULL,0,0L,1L)) <= 0))
			return(i);

	CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

	if ((a->method == NULL) || (a->method->destroy == NULL)) return(1);
	a->method->destroy(a);
	OPENSSL_free(a);
	return(1);
}
