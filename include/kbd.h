/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
#include <sccsid.h>
HVERSION(kbd,@(#)kbd.h	2.3);
*/
#define	TTY_CHIRP	0x10
#define	TTY_ALARM	0x08
#define	RPTON		0x100
#define	RPTHAVECHR	0x200
#define	RPTLOOKUP	0x400
#define	RPTMASK		0x700
#define KBD_INIT_STATUS	0xfe	/* initial status of kbd, needed for selftest */
