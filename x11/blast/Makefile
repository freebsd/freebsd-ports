# New ports collection makefile for:   blast-1.0
# Version required:       1.0
# Date created:         9 Jul 1996
# Whom:            searle
#
# $Id: porting.sgml,v 1.11 1995/12/07 13:22:15 jkh Exp $
#

DISTNAME=	blast-1.0-ss-9.03
PKGNAME=	blast-1.0
CATEGORIES+=	x11
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/X11/Demos/blast-1.0/ \
		ftp://ftp.ask.uni-karlsruhe.de/pub/hpux/X11/Demos/blast-1.0/ \
		ftp://ftp.univie.ac.at/systems/hpux/hpux/X11/Demos/blast-1.0/ \
		ftp://hpftp.cict.fr/hpux/X11/Demos/blast-1.0/ \
		ftp://parnas.mimuw.edu.pl/hpux/X11/Demos/blast-1.0/

MAINTAINER=	searle@longacre.demon.co.uk

USE_X11=	yes

MANDIR=		$(PREFIX)/man/man1

pre-configure:
	mv $(WRKDIR)/blast-1.0 $(WRKSRC)

do-build:
	cc $(WRKSRC)/blast.c -I/usr/X11R6/include -O2 -L$(PREFIX)/lib -lX11 -lXext -o $(WRKSRC)/blast

do-install:
	$(INSTALL) -c $(WRKSRC)/blast $(PREFIX)/bin/blast
	$(INSTALL) -c $(WRKSRC)/blast.man $(DESTDIR)$(MANDIR)/blast.1
.if !defined(NOMANCOMPRESS)
	gzip -9 $(MANDIR)/blast.1
.endif

.include <bsd.port.mk>
