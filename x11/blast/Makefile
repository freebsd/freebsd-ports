# New ports collection makefile for:   blast-1.0
# Version required:       1.0
# Date created:         9 Jul 1996
# Whom:            searle
#
# $Id: Makefile,v 1.3 1996/11/13 12:41:35 asami Exp $
#

DISTNAME=	blast-1.0-ss-9.03
PKGNAME=	blast-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/X11/Demos/blast-1.0/ \
		ftp://ftp.ask.uni-karlsruhe.de/pub/hpux/X11/Demos/blast-1.0/ \
		ftp://ftp.univie.ac.at/systems/hpux/hpux/X11/Demos/blast-1.0/ \
		ftp://hpftp.cict.fr/hpux/X11/Demos/blast-1.0/ \
		ftp://parnas.mimuw.edu.pl/hpux/X11/Demos/blast-1.0/

MAINTAINER=	searle@longacre.demon.co.uk

USE_X11=	yes
MAN1=		blast.1

pre-configure:
	mv $(WRKDIR)/blast-1.0 $(WRKSRC)

do-build:
	cc $(WRKSRC)/blast.c -I/usr/X11R6/include -O2 -L$(PREFIX)/lib -lX11 -lXext -o $(WRKSRC)/blast

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/blast $(PREFIX)/bin/blast
	$(INSTALL_MAN) $(WRKSRC)/blast.man $(PREFIX)/man/man1/blast.1

.include <bsd.port.mk>
