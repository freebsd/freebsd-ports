PORTNAME=	terminal
DISTVERSION=	8.1.0
CATEGORIES=	x11
PKGNAMEPREFIX=	elementary-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal emulator designed for elementary OS
WWW=		https://github.com/elementary/terminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite-7.so:x11-toolkits/granite7 \
		libpcre2-posix.so:devel/pcre2

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig \
		vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 libadwaita vte3
GLIB_SCHEMAS=	io.elementary.terminal.gschema.xml

.include <bsd.port.mk>
