PORTNAME=	editres
DISTVERSION=	1.1.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Dynamic resource editor for X Toolkit Applications
WWW=		https://gitlab.freedesktop.org/xorg/app/editres

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbfile.so:x11/libxkbfile

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xaw xmu xorgproto xt

.include <bsd.port.mk>
