PORTNAME=	cinnamon-session
PORTVERSION=	5.4.0
PORTREVISION=	3
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the cinnamon desktop
WWW=		https://github.com/linuxmint/cinnamon-session

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxapp.so:x11/xapp \
		libcanberra.so:audio/libcanberra
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2

USES=		gl gnome meson pkgconfig python:build shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_FILES=	data/meson_install_schemas.py

USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	ice sm x11 xau xcomposite xext xrender xtrans xtst
USE_GL=		gl

GLIB_SCHEMAS=	org.cinnamon.SessionManager.gschema.xml

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=	IPV6

IPV6_MESON_TRUE=	ipv6

.include <bsd.port.mk>
