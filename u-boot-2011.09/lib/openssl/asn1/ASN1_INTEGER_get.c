/*
 * lib/openssl/asn1/ASN1_INTEGER_get.c
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
#include"x509.h"


///////////X509_get_serialNumber///////////////////ok

ASN1_INTEGER *X509_get_serialNumber(X509 *a)
	{
	return(a->cert_info->serialNumber);
	}

