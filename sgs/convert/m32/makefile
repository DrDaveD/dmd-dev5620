# 
#									
#	Copyright (c) 1987,1988,1989,1990,1991,1992   AT&T		
#			All Rights Reserved				
#									
#	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		
#	    The copyright notice above does not evidence any		
#	   actual or intended publication of such source code.		
#									
# 
#
#	BELLMAC-32 CONVERT MAKEFILE
#
#	@(#) makefile: 1.9 9/15/83
#
SGS=m32
CC=cc
DMD=/usr/local/dmd
EXTRACFLAGS=-O
CFLAGS=-c -DDMD=\"$(DMD)\" $(EXTRACFLAGS)
ARCH=AR32WR
APPL=NONE
#	Set ARFORMAT to "PORTAR" for portable archive format (post 5.0)
ARFORMAT=PORTAR
#	Set FLEX to -DFLEXNAMES for flexnames  (post 6.0)
FLEX= -DFLEXNAMES
DEFLIST=-D$(ARCH) -D$(ARFORMAT) -D$(APPL) $(FLEX)
INCLIST=-I. -I$(COMINC) -I$(M32INC) -I$(USRINC)
ENV=
FFLAG=
CC_CMD=$(CC) $(CFLAGS) $(DEFLIST) $(INCLIST) $(ENV)
#
LD=$(CC)
LDFLAGS= $(FFLAG)
LD_CMD=$(LD) $(LDFLAGS)
#
STRIP=strip
SPFLAGS=
STRIP_CMD=$(STRIP) $(SPFLAGS)
#
LINT=lint
LINTFLAGS=-p
LINT_CMD=$(LINT) $(LINTFLAGS)
#
#	Internal Directories
#
BASE= ../..
BINDIR= $(BASE)/xenv/m32/bin
LIBDIR= $(BASE)/xenv/m32/lib
COMINC= $(BASE)/inc/common
M32INC= $(BASE)/inc/m32
COMCONV= $(BASE)/convert/common
ROOT=
VERSION=
USRINC=$(ROOT)/usr/$(VERSION)include
#
LIBLD	= $(BASE)/libld/m32/libld.a
#
OBJECTS= main.o getargs.o convert.o fcns.o openobject.o util.o appl.o
#
all:		conv
#
conv:		makefile $(OBJECTS) $(LIBLD)
	$(LD_CMD) -o conv $(OBJECTS) $(LIBLD)
#
main.o:		$(COMCONV)/conv.h $(COMCONV)/main.c makefile
	$(CC_CMD) $(COMCONV)/main.c
#
getargs.o:	$(COMCONV)/conv.h $(COMINC)/sgsmacros.h $(COMINC)/filehdr.h makefile \
		$(COMCONV)/getargs.c
	$(CC_CMD) $(COMCONV)/getargs.c
#
convert.o:	$(COMINC)/filehdr.h $(COMINC)/ldfcn.h makefile \
		$(COMCONV)/conv.h \
		$(COMCONV)/convert.c
	$(CC_CMD) $(COMCONV)/convert.c
#
fcns.o:		$(COMCONV)/conv.h $(COMINC)/filehdr.h $(COMINC)/ldfcn.h \
		$(COMINC)/linenum.h $(COMINC)/patch.h $(COMINC)/reloc.h \
		$(COMINC)/scnhdr.h $(COMINC)/storclass.h $(COMINC)/syms.h \
		$(COMINC)/aouthdr.h makefile \
		$(COMCONV)/fcns.c
	$(CC_CMD) $(COMCONV)/fcns.c
#
openobject.o:	$(COMCONV)/conv.h $(COMINC)/filehdr.h $(COMINC)/ldfcn.h \
		makefile \
		$(COMCONV)/openobject.c
	$(CC_CMD) $(COMCONV)/openobject.c
#
util.o:		$(COMCONV)/conv.h $(COMINC)/filehdr.h $(COMINC)/ldfcn.h \
		$(COMINC)/aouthdr.h $(COMINC)/scnhdr.h makefile \
		$(COMCONV)/util.c
	$(CC_CMD) $(COMCONV)/util.c
#
appl.o:		$(COMINC)/filehdr.h $(COMINC)/ldfcn.h $(COMCONV)/conv.h \
		$(COMINC)/aouthdr.h makefile \
		$(COMCONV)/appl.c
	$(CC_CMD) $(COMCONV)/appl.c
#
install:	$(BINDIR)/$(SGS)conv
#
$(BINDIR)/$(SGS)conv:	conv
	-rm -f $(BINDIR)/$(SGS)conv
	cp conv $(BINDIR)/$(SGS)conv
	-$(STRIP_CMD) $(BINDIR)/$(SGS)conv
#
save:	$(BINDIR)/$(SGS)conv
	-rm -f $(BINDIR)/$(SGS)conv.back
	cp $(BINDIR)/$(SGS)conv $(BINDIR)/$(SGS)conv.back
#
stripit:	uninstall
uninstall:
	-rm -f $(BINDIR)/$(SGS)conv
#
clean:	shrink
shrink:
	rm -f $(OBJECTS) conv
