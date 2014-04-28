# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11/gnome-shell/Makefile 19422 2014-03-31 21:02:35Z kwm $

PORTNAME=	gnome-shell
PORTVERSION=	3.12.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-control-center>=0:${PORTSDIR}/sysutils/gnome-control-center
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libcaribou.so:${PORTSDIR}/accessibility/caribou \
		libmutter.so:${PORTSDIR}/x11-wm/mutter \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libtelepathy-logger.so:${PORTSDIR}/net-im/telepathy-logger \
		libfolks.so:${PORTSDIR}/net-im/folks \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libcroco-0.6.so:${PORTSDIR}/textproc/libcroco \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libgjs.so:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		gdm>=0:${PORTSDIR}/x11/gdm \
		gnome-control-center>=0:${PORTSDIR}/sysutils/gnome-control-center \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz \
		webplugin:native
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gnomeprefix \
		gtk30 intlhack introspection
USE_XORG=	x11 xfixes sm
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WEBPLUGIN_DIR=	${PREFIX}/lib/
WEBPLUGIN_FILES=libgnome-shell-browser-plugin.so
CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV+=	BROWSER_PLUGIN_DIR=${PREFIX}/lib/
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c
	@${REINPLACE_CMD} -e 's|\-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/browser-plugin/Makefile.in
	@${REINPLACE_CMD} -e 's|libnm-glib libnm-util ||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-shell/libgnome-shell*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnome-shell-browser-plugin.so

.include <bsd.port.mk>
