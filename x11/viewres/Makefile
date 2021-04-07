PORTNAME=	viewres
PORTVERSION=	1.0.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Graphical class browser for Xt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11 xaw xmu xt

PLIST_FILES+=	bin/viewres \
		man/man1/viewres.1.gz \
		share/X11/app-defaults/Viewres \
		share/X11/app-defaults/Viewres-color

.include <bsd.port.mk>
