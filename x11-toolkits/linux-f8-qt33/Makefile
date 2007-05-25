# New ports collection makefile for:	linux-qt33
# Date created:				24 May 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qt33
PORTVERSION=	3.3.4
CATEGORIES=	x11-toolkits linux
DISTNAME=	qt-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	RPM of QT3

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libmng.so.1:${PORTSDIR}/graphics/linux-libmng \
		${LINUXBASE}/usr/lib/libpng12.so.0:${PORTSDIR}/graphics/linux-png

USE_LINUX_RPM=	yes
RPMVERSION=	15.5
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
