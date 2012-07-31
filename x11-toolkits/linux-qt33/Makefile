# New ports collection makefile for:	linux-qt33
# Date created:				24 May 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qt33
PORTVERSION=	3.3.4
PORTREVISION=	4
CATEGORIES=	x11-toolkits linux
DISTNAME=	qt-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	RPM of QT3

CONFLICTS=	linux-f8-qt33-[0-9]* linux-f10-qt33-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig libmng png
RPMVERSION=	15.5
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
