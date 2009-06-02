# New ports collection makefile for:	x11-toolkits/linux-f10-tk85
# Date created:				2009-05-04
# Whom:					bsam
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	8.5.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f10-
PKGNAMESUFFIX=	85
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux Fedora 10)

CONFLICTS=	linux-f8-tk84-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	10
RPMVERSION=	5.fc10
BRANELF_FILES=	usr/bin/wish8.5
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
