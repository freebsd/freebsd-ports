# New ports collection makefile for:	x11-toolkits/linux-f8-pango
# Date created:				2008-03-29
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.18.4
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	The pango library (Linux Fedora 8)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
# these libraries are required by pango-querymodules
USE_LINUX_APPS=	cairo expat fontconfig xorglibs
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
BRANDELF_FILES=	usr/bin/pango-querymodules-32
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
	@${PREFIX}/usr/bin/pango-querymodules-32 > ${PREFIX}/etc/pango/i386-redhat-linux-gnu/pango.modules

.include <bsd.port.mk>
