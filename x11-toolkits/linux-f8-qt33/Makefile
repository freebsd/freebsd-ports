# New ports collection makefile for:	x11-toolkits/linux-f8-qt33
# Date created:				2008-04-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	${LINUX_NAME}33
PORTVERSION=	3.3.8b
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT3 (Linux Fedora 8)

CONFLICTS=	linux-qt33-[0-9]* linux-f10-qt33-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig libmng png
LINUX_NAME=	qt
LINUX_DIST_VER=	8
RPMVERSION=	2.fc8
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
