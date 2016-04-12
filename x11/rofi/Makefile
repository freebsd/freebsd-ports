# $FreeBSD$

PORTNAME=	rofi
PORTVERSION=	0.15.12
CATEGORIES=	x11

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	Window switcher, run dialog and dmenu replacement

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

USE_GITHUB=	yes
GH_ACCOUNT=	DaveDavenport

GNU_CONFIGURE=	yes
USES=		autoreconf gmake pkgconfig shebangfix
SHEBANG_FILES=	${WRKSRC}/script/rofi-sensible-terminal
USE_XORG=	x11 xinerama xft
USE_GNOME=	pango

OPTIONS_DEFINE=	I3

I3_DESC=	I3 support
I3_BUILD_DEPENDS=	i3:x11-wm/i3
I3_CFLAGS=	-I${LOCALBASE}/include

PLIST_FILES=	bin/rofi bin/rofi-sensible-terminal man/man1/rofi.1.gz \
		man/man1/rofi-sensible-terminal.1.gz

.include <bsd.port.mk>
