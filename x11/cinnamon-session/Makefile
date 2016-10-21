# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-session
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the cinnamon desktop

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libjson-glib-1.0.so:devel/json-glib \
		libupower-glib.so:sysutils/upower \
		libcanberra.so:audio/libcanberra
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit \
		xdpyinfo:x11/xdpyinfo

USES=		autoreconf:build execinfo gettext gmake libtool \
		pathfix pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_XORG=	ice sm xau xext xtst xrender xtrans xcomposite
USE_GL=		gl
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral -Wno-error=implicit-function-declaration
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral -Wno-error=implicit-function-declaration
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.SessionManager.gschema.xml

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
