/*
 * lib/openssl/asn1/RSAPublicKey_it.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include "asn1.h"
#include "asn1t.h"
#include "x509v3.h"
#include "rsa.h"
#include "bn.h"
#include"ossl_typ.h"
#include"myfunction.h"

/////////////////////rsa_cb/////////////////////////////////

static int rsa_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it)
{
	if(operation == ASN1_OP_NEW_PRE) {
		*pval = (ASN1_VALUE *)RSA_new();
		if(*pval) return 2;
		return 0;
	} else if(operation == ASN1_OP_FREE_PRE) {
		//RSA_free((RSA *)*pval);//samyang delete
		*pval = NULL;
		return 2;
	}
	return 1;
}


////////////////RSAPublicKey_it//////////////////////////////////////

ASN1_SEQUENCE_cb(RSAPublicKey, rsa_cb) = {
	ASN1_SIMPLE(RSA, n, BIGNUM),
	ASN1_SIMPLE(RSA, e, BIGNUM),
} ASN1_SEQUENCE_END_cb(RSA, RSAPublicKey)

IMPLEMENT_ASN1_ENCODE_FUNCTIONS_const_fname(RSA, RSAPublicKey, RSAPublicKey)

