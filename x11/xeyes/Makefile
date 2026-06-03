PORTNAME=	xeyes
DISTVERSION=	1.3.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Follow the mouse X demo
WWW=		https://gitlab.freedesktop.org/xorg/app/xeyes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xcb xext xi xmu xorgproto xrender xt

PLIST_FILES=	bin/xeyes share/man/man1/xeyes.1.gz

.include <bsd.port.mk>
