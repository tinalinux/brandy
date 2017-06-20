/*
 * include/openssl/opensslv.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef HEADER_OPENSSLV_H
#define HEADER_OPENSSLV_H


#define OPENSSL_VERSION_NUMBER	0x0090812fL
#ifdef OPENSSL_FIPS
#define OPENSSL_VERSION_TEXT	"OpenSSL 0.9.8r-fips 8 Feb 2011"
#else
#define OPENSSL_VERSION_TEXT	"OpenSSL 0.9.8r 8 Feb 2011"
#endif
#define OPENSSL_VERSION_PTEXT	" part of " OPENSSL_VERSION_TEXT



#define SHLIB_VERSION_HISTORY ""
#define SHLIB_VERSION_NUMBER "0.9.8"


#endif /* HEADER_OPENSSLV_H */
