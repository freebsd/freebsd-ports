# New ports collection makefile for:	x11-toolkits/linux-f10-pango
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.28.3
DISTVERSIONSUFFIX=	-1.fc10
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	netchild/rpms/${LINUX_DIST}${LINUX_DIST_VER}
MASTER_SITE_SRC_SUBDIR=	netchild/rpms/${LINUX_DIST}${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The pango library (Linux Fedora 10)

CONFLICTS=	linux-pango-[0-9]* linux-f8-pango-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
# these libraries are required by pango-querymodules
USE_LINUX_APPS=	cairo expat fontconfig xorglibs
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
BRANDELF_FILES=	usr/bin/pango-querymodules-32
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
	@${PREFIX}/usr/bin/pango-querymodules-32 > ${PREFIX}/etc/pango/i686-pc-linux-gnu/pango.modules

.include <bsd.port.mk>
