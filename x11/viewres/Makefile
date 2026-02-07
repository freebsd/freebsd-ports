PORTNAME=	viewres
DISTVERSION=	1.0.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Graphical class browser for Xt
WWW=		https://gitlab.freedesktop.org/xorg/app/viewres

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xaw xmu xorgproto xt

PLIST_FILES+=	bin/viewres \
		share/man/man1/viewres.1.gz \
		share/X11/app-defaults/Viewres \
		share/X11/app-defaults/Viewres-color

.include <bsd.port.mk>
