# New ports collection makefile for:   linux-xalf
# Date created:        17 January 2002
# Whom:                Joe Marcus Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	xalf
PORTVERSION=	0.12
CATEGORIES=	x11 linux
MASTER_SITES=	http://www.lysator.liu.se/~astrand/projects/xalf/ \
				http://www.lysator.liu.se/~astrand/projects/xalf/old/
DISTNAME=	xalf-0.12-1.i386
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	.rpm

MAINTAINER=	gnome@freebsd.org

LIB_DEPENDS=	xalflaunch.0:${PORTSDIR}/x11/xalf
BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio
USE_LINUX_PREFIX=	yes

EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| cpio -id --quiet
XALFDIR=	/compat/linux/usr/X11R6/lib
WRKSRC=		${WRKDIR}/usr/lib

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libxalflaunch.so.0.0.1 \
		${XALFDIR}/libxalflaunch.so.0

.include <bsd.port.post.mk>
