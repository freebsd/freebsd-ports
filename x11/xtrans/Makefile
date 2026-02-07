PORTNAME=	xtrans
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/lib/libxtrans/-/commit/
PATCHFILES+=	4e6763a5914c.patch:-p1 # https://gitlab.freedesktop.org/xorg/lib/libxtrans/-/merge_requests/8

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Abstract network code for X

LICENSE=	MIT

USES=		tar:xz xorg-cat:lib

CONFIGURE_ARGS+=--disable-docs --without-xmlto
NO_ARCH=	yes

.include <bsd.port.mk>
