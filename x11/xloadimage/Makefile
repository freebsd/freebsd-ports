# New ports collection makefile for:    xloadimage
# Version required:     3.03
# Date created:         9 January 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	xloadimage
PKGNAME=	xloadimage-3.03
CATEGORIES+=	x11
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/X11-contrib/
DISTFILES=	xloadimage.3.03.tar.Z

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults -f

pre-install:
	@mkdir -p ${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
