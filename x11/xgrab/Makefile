# New ports collection makefile for:    xgrab
# Version required:     2.3
# Date created:         27 February 1995
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	xgrabsc.2_3
PKGNAME=	xgrab-2.3
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.sunet.se/pub/X11/R5contrib/

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/app-defaults  -f

.include <bsd.port.mk>
