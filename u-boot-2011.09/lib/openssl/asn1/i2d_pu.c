/*
 * lib/openssl/asn1/i2d_pu.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include "cryptlib.h"
#include "bn.h"
#include "evp.h"
#include "objects.h"
#ifndef OPENSSL_NO_RSA
#include "rsa.h"
#endif


int i2d_PublicKey(EVP_PKEY *a, unsigned char **pp)
	{
	switch (a->type)
		{
#ifndef OPENSSL_NO_RSA
	case EVP_PKEY_RSA:
		return(i2d_RSAPublicKey(a->pkey.rsa,pp));
#endif

	default:
		ASN1err(ASN1_F_I2D_PUBLICKEY,ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE);
		return(-1);
		}
	}

