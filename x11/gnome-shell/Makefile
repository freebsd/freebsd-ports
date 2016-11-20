# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell
PORTVERSION=	3.18.4
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gnome-control-center:sysutils/gnome-control-center
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libcaribou.so:accessibility/caribou \
		libmutter.so:x11-wm/mutter \
		libsecret-1.so:security/libsecret \
		libgcr-3.so:security/gcr \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libfolks.so:net-im/folks \
		libibus-1.0.so:textproc/ibus \
		libpulse.so:audio/pulseaudio \
		libcroco-0.6.so:textproc/libcroco \
		libdbus-glib-1.so:devel/dbus-glib \
		libclutter-1.0.so:graphics/clutter \
		libgjs.so:lang/gjs
RUN_DEPENDS=	py*-dbus>=0:devel/py-dbus \
		gnome-control-center:sysutils/gnome-control-center \
		ca_root_nss>=0:security/ca_root_nss \
		gkbd-keyboard-display:x11/libgnomekbd

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe gettext gmake gnome libtool pathfix \
		pkgconfig tar:xz webplugin:native
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gtk30 intlhack \
		introspection
USE_XORG=	x11 xfixes sm
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WEBPLUGIN_NAME=	libgnome-shell-browser-plugin.so
WEBPLUGIN_DIR=	${PREFIX}/lib/mozilla/plugins/
WEBPLUGIN_FILES=libgnome-shell-browser-plugin.so
CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c
	@${REINPLACE_CMD} -e 's|\-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/browser-plugin/Makefile.in
	@${REINPLACE_CMD} -e 's|libnm-glib libnm-util ||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
