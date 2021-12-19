PORTNAME=	terminal
DISTVERSION=	6.0.1
CATEGORIES=	x11
PKGNAMEPREFIX=	elementary-

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Terminal emulator designed for elementary OS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libpcre2-posix.so:devel/pcre2

USES=		desktop-file-utils gettext gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 vte3
GLIB_SCHEMAS=	io.elementary.terminal.gschema.xml

.include <bsd.port.mk>
