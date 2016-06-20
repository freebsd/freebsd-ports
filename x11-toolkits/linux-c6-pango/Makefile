# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	1.28.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org

COMMENT=	Pango library (Linux  CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-pango-[0-9]* linux-f10-pango-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_APPS=	cairo expat fontconfig xorglibs
USE_LINUX_RPM=	yes
RPMVERSION=	11.el6

BRANDELF_FILES=	usr/bin/pango-querymodules-32
.if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == "c6_64"
BRANDELF_FILES+=	usr/bin/pango-querymodules-64
.endif

USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
