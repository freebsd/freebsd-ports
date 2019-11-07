# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktray
PORTVERSION=	1.3.9
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/tktray/tktray1.3.9.tar.gz/6f7f22e7c6f1d7dc9f7e19ee2e9a82aa/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	System tray icon support

USES+=		tk:tea xorg
USE_XORG=	x11 xext

PLIST_FILES=	lib/${TCL_PKG}/libtktray.so.1 \
		lib/${TCL_PKG}/pkgIndex.tcl \
		man/mann/${PORTNAME}.n.gz

.include <bsd.port.mk>
