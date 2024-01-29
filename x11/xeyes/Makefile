PORTNAME=	xeyes
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Follow the mouse X demo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xcb xext xi xmu xrender xt

PLIST_FILES=	bin/xeyes share/man/man1/xeyes.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
