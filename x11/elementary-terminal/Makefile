PORTNAME=	terminal
DISTVERSION=	6.0.0
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
		libpcre2-posix.so:devel/pcre2 \
		libvte-2.91.so:x11-toolkits/vte3

USES=		desktop-file-utils gettext gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	glib20 gtk30
GLIB_SCHEMAS=	io.elementary.terminal.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
