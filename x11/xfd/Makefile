PORTNAME=	xfd
DISTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display all characters in an X font
WWW=		https://gitlab.freedesktop.org/xorg/app/xfd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		tar:xz xorg xorg-cat:app,meson
USE_XORG=	x11 xaw xft xkbfile xmu xorgproto xrender xt

.include <bsd.port.mk>
