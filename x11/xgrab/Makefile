# New ports collection makefile for:    xgrab
# Version required:     2.41
# Date created:         27 February 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.12 1998/09/26 23:20:10 steve Exp $
#

DISTNAME=	xgrabsc.2_41
PKGNAME=	xgrab-2.41
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f
# "make depend" blows up
XMKMF=		xmkmf
# Needs to actually *run* xrdb
#IS_INTERACTIVE=	yes
.if !defined(DISPLAY)
BROKEN=		Requires an active X session to run xrdb.  Please compile this while running X.
.endif

MAN1=		xgrab.1 xgrabsc.1

.include <bsd.port.mk>
