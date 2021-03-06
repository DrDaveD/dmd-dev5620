/* */
/*									*/
/*	Copyright (c) 1987,1988,1989,1990,1991,1992   AT&T		*/
/*			All Rights Reserved				*/
/*									*/
/*	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		*/
/*	    The copyright notice above does not evidence any		*/
/*	   actual or intended publication of such source code.		*/
/*									*/
/* */
/* @(#) ldmacros.h: 1.2 3/14/83 */
#define MAXKEEPSIZE	1024

extern char	stat_name[];
#if FLEXNAMES
#define	PTRNAME(x)	((x)->n_zeroes == 0L) \
				? (x)->n_nptr \
				: strncpy( stat_name, (x)->n_name, 8 )
#define SYMNAME(x)	(x.n_zeroes == 0L) \
				? x.n_nptr \
				: strncpy( stat_name, x.n_name, 8 )
#else
#define PTRNAME(x)	strncpy( stat_name, (x)->n_name, 8 )
#define SYMNAME(x)	strncpy( stat_name, x.n_name, 8 )
#endif

#if NOSDP
#define PUTSYM(x,y)
#define PUTAUX(x,y)
#else
#define PUTSYM(x,y)	putsym(x,y)
#define PUTAUX(x,y)	putaux(x,y)
#endif

#define OKSCNNAME(x)	((tvflag && (!rflag || aflag)) || strncmp( x, _TV, 8 ))
