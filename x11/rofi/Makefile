# $FreeBSD$

PORTNAME=	rofi
PORTVERSION=	0.14.12
CATEGORIES=	x11
MASTER_SITES=	GH GHC

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	Window switcher, run dialog and dmenu replacement

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	DaveDavenport
GH_COMMIT=	9b33197
GH_TAGNAME=	0.14.12

GNU_CONFIGURE=	yes
USES=		autoreconf pkgconfig
USE_XORG=	x11 xinerama
USE_GNOME=	pango

PLIST_FILES=	bin/rofi man/man1/rofi.1.gz

.include <bsd.port.mk>
