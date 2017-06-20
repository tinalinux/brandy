/*
 * tools/ncb.c
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
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main (int argc, char *argv[])
{
	int s, len, o, port = 6666;
	char buf[512];
	struct sockaddr_in addr;
	socklen_t addr_len = sizeof addr;

	if (argc > 1)
		port = atoi (argv[1]);

	s = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	o = 1;
	len = 4;
	setsockopt (3, SOL_SOCKET, SO_REUSEADDR, &o, len);

	addr.sin_family = AF_INET;
	addr.sin_port = htons (port);
	addr.sin_addr.s_addr = INADDR_ANY;	/* receive broadcasts */

	bind (s, (struct sockaddr *) &addr, sizeof addr);

	for (;;) {
		len = recvfrom (s, buf, sizeof buf, 0, (struct sockaddr *) &addr, &addr_len);
		if (len < 0)
			break;
		if (write (1, buf, len) != len)
			fprintf(stderr, "WARNING: serial characters dropped\n");
	}

	return 0;
}
