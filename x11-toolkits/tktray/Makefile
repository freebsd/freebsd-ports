# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktray
PORTVERSION=	1.3.9
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	System tray icon support

USES+=		tk:tea
USE_XORG=	x11 xext

PLIST_FILES=	lib/${TCL_PKG}/libtktray.so.1 \
		lib/${TCL_PKG}/pkgIndex.tcl \
		man/mann/${PORTNAME}.n.gz

.include <bsd.port.mk>
