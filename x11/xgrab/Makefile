# New ports collection makefile for:    xgrab
# Date created:         27 February 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xgrab
PORTVERSION=	2.41
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	${PORTNAME}sc.2_41
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 image grabber

BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USE_XORG=	x11
USE_IMAKE=	yes
USE_DISPLAY=	yes

MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f
# "make depend" blows up
XMKMF=		xmkmf

BROKEN=		fails to build with xorg 7.5

.if (!defined(DISPLAY) || ${DISPLAY} == "") && !defined(PACKAGE_BUILDING)
IGNORE=		Requires an active X session (and DISPLAY variable) to run xrdb.  Please compile this while running X.
.endif

MAN1=		xgrab.1 xgrabsc.1

.include <bsd.port.mk>
