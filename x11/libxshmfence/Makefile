# $FreeBSD$

PORTNAME=	libxshmfence
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Shared memory 'SyncFence' synchronization primitive

LICENSE=	MIT

USE_XORG=	xorgproto
XORG_CAT=	lib

CONFIGURE_ARGS=	--with-shared-memory-dir=/tmp
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
