# New ports collection makefile for:	x11-toolkits/linux-f10-qt33
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	${LINUX_NAME}3
PORTVERSION=	3.3.8b
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT3 (Linux Fedora 10)

CONFLICTS=	linux-qt33-[0-9]* linux-f8-qt33-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig libmng png
LINUX_NAME=	qt3
LINUX_DIST_VER=	10
RPMVERSION=	17.fc10
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
