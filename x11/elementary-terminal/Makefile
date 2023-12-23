PORTNAME=	terminal
DISTVERSION=	6.1.1
PORTREVISION=	2
CATEGORIES=	x11
PKGNAMEPREFIX=	elementary-

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Terminal emulator designed for elementary OS
WWW=		https://github.com/elementary/terminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libpcre2-posix.so:devel/pcre2

USES=		desktop-file-utils gettext gnome meson pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 vte3
GLIB_SCHEMAS=	io.elementary.terminal.gschema.xml

.include <bsd.port.mk>
