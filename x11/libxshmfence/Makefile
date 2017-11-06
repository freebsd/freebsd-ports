# $FreeBSD$

PORTNAME=	libxshmfence
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Shared memory 'SyncFence' synchronization primitive

LICENSE=	MIT

USE_XORG=	xproto
XORG_CAT=	lib

CONFIGURE_ARGS=	--with-shared-memory-dir=/tmp
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
