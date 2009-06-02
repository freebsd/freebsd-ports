# New ports collection makefile for:	linux-qt33
# Date created:				24 May 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qt33
PORTVERSION=	3.3.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
DISTNAME=	qt-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	RPM of QT3

CONFLICTS=	linux-f8-qt33-[0-9]* linux-f10-qt33-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig libmng png
RPMVERSION=	15.5
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
