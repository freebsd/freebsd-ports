PORTNAME=	libxshmfence
DISTVERSION=	1.3.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Shared memory 'SyncFence' synchronization primitive
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxshmfence

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto

CONFIGURE_ARGS=	--with-shared-memory-dir=/tmp
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
