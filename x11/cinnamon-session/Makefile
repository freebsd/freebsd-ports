# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/cinnamon-session/Makefile 19789 2014-08-05 07:43:54Z gusi $

PORTNAME=	cinnamon-session
PORTVERSION=	2.2.2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the cinnamon desktop

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcanberra.so:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

USES=		execinfo gettext gmake libtool pathfix pkgconfig tar:xz
USE_XORG=	ice sm xau xext xtst xrender xtrans xcomposite
USE_GL=		gl
USE_GNOME=	gnomeprefix gtk30 intltool
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
PATHFIX_MAKEFILEIN=	Makefile.am
CONFIGURE_ARGS=	--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral -Wno-error=implicit-function-declaration
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral -Wno-error=implicit-function-declaration
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.SessionManager.gschema.xml

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
