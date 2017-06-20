/*
 * lib/openssl/asn1/ASN1_STRING_print.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include"asn1.h"
#include"err.h"
#include"myfunction.h"

int ASN1_STRING_print(BIO *bp, ASN1_STRING *v)
	{
	int i,n;
	char buf[80],*p;

	if (v == NULL) return(0);
	n=0;
	p=(char *)v->data;
	for (i=0; i<v->length; i++)
		{
//		if ((p[i] > '~') || ((p[i] < ' ') &&
//			(p[i] != '\n') && (p[i] != '\r')))
//			buf[n]='.';
//		else
			buf[n]=p[i];
		n++;
		if (n >= 80)
			{
			if (BIO_write(bp,buf,n) <= 0)
				return(0);
			n=0;
			}
		}
	if (n > 0)
		if (BIO_write(bp,buf,n) <= 0)
			return(0);
	return(1);
	}

