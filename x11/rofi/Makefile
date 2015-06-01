# $FreeBSD$

PORTNAME=	rofi
PORTVERSION=	0.15.2
CATEGORIES=	x11

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	Window switcher, run dialog and dmenu replacement

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	DaveDavenport

GNU_CONFIGURE=	yes
USES=		autoreconf pkgconfig gmake
USE_XORG=	x11 xinerama xft
USE_GNOME=	pango

PLIST_FILES=	bin/rofi man/man1/rofi.1.gz

.include <bsd.port.mk>
