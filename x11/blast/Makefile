# New ports collection makefile for:   blast-1.0
# Version required:       1.0
# Date created:         9 Jul 1996
# Whom:            searle
#
# $Id: Makefile,v 1.7 1998/04/11 02:35:57 jseger Exp $
#

DISTNAME=	blast-1.0-ss-10.20
PKGNAME=	blast-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/X11/Demos/blast-1.0/ \
		ftp://ftp.univie.ac.at/systems/hpux/hpux/X11/Demos/blast-1.0/ \
		ftp://hpftp.cict.fr/hpux/X11/Demos/blast-1.0/

MAINTAINER=	jseger@FreeBSD.org

USE_X_PREFIX=	yes
MAN1=		blast.1
WRKSRC=		${WRKDIR}/blast-1.0

do-build:
	cc $(WRKSRC)/blast.c -I${X11BASE}/include -O2 -L$(PREFIX)/lib -lX11 -lXext -o $(WRKSRC)/blast

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/blast $(PREFIX)/bin/blast
	$(INSTALL_MAN) $(WRKSRC)/blast.man $(PREFIX)/man/man1/blast.1

.include <bsd.port.mk>
