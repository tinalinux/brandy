/*
 * tools/xway-swap-bytes.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFSIZ
# define BUFSIZ 4096
#endif

#undef BUFSIZ
# define BUFSIZ 64
int main (void)
{
	short ibuff[BUFSIZ], obuff[BUFSIZ];
	int rc, i, len;

	while ((rc = read (0, ibuff, sizeof (ibuff))) > 0) {
		memset (obuff, 0, sizeof (obuff));
		for (i = 0; i < (rc + 1) / 2; i++) {
			obuff[i] = ibuff[i ^ 1];
		}

		len = (rc + 1) & ~1;

		if (write (1, obuff, len) != len) {
			perror ("read error");
			return (EXIT_FAILURE);
		}

		memset (ibuff, 0, sizeof (ibuff));
	}

	if (rc < 0) {
		perror ("read error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
