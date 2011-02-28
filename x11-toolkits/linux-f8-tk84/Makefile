# New ports collection makefile for:    x11-toolkits/linux-f8-tk84
# Date created:				11-08-2008
# Whom:					Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	8.4.17
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f8-
PKGNAMESUFFIX=	84
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Graphical toolkit for TCL (Linux Fedora 8)

CONFLICTS=	linux-f10-tk85-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	8
RPMVERSION=	2.fc8
BRANELF_FILES=	usr/bin/wish8.4
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION}<700055
	IGNORE= You need at least FreeBSD>=7.0 RELEASE with Linux emulation 2.6.x
.endif

.include <bsd.port.post.mk>
