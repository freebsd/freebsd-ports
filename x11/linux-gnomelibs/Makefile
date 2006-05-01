# New ports collection makefile for: linux-gnomelibs
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomelibs
PORTVERSION=	1.4.1.2.90
CATEGORIES=	x11 linux
DISTNAME=	gnome-libs-${PORTVERSION}-44

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of gnome-libs

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin usr/sbin

.include <bsd.port.mk>
