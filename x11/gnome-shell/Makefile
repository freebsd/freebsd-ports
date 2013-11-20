# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-shell/Makefile 18582 2013-06-23 10:52:15Z kwm $

PORTNAME=	gnome-shell
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
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
		gdm>=3.6.0:${PORTSDIR}/x11/gdm \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_XZ=		yes
USE_XORG=	x11 xfixes sm
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gnomemenus3 gnomeprefix \
		gtk30 intlhack introspection ltverhack
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml

CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV+=	BROWSER_PLUGIN_DIR=${PREFIX}/lib/browser_plugins
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c
	@${REINPLACE_CMD} -e 's|\-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/browser-plugin/Makefile.in 
	@${REINPLACE_CMD} -e 's|libnm-glib libnm-util ||g' \
		${WRKSRC}/configure

post-install:	
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-shell/libgnome-*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/browser_plugins/libgnome-shell-browser-plugin.so

.include <bsd.port.mk>
