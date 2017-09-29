# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell
PORTVERSION=	3.18.5
PORTREVISION=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		nss>=0:security/nss \
		gnome-control-center:sysutils/gnome-control-center
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libcaribou.so:accessibility/caribou \
		libmutter.so:x11-wm/mutter \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libnspr4.so:devel/nspr \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libgcr-3.so:security/gcr \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libibus-1.0.so:textproc/ibus \
		libical.so:devel/libical \
		libmozjs-24.so:lang/spidermonkey24 \
		libicuuc.so:devel/icu \
		libpulse.so:audio/pulseaudio \
		libcroco-0.6.so:textproc/libcroco \
		libdbus-glib-1.so:devel/dbus-glib \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libp11-kit.so:security/p11-kit \
		libpolkit-gobject-1.so:sysutils/polkit \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libgjs.so:lang/gjs
RUN_DEPENDS=	py*-dbus>=0:devel/py-dbus \
		nss>=0:security/nss \
		gnome-control-center:sysutils/gnome-control-center \
		ca_root_nss>=0:security/ca_root_nss \
		gkbd-keyboard-display:x11/libgnomekbd

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe gettext gmake gnome libtool localbase \
		pathfix pkgconfig sqlite tar:xz webplugin:native
USE_GNOME=	cairo evolutiondataserver3 gdkpixbuf2 gtk30 intltool \
		introspection libxml2
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USE_GL=		egl
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WEBPLUGIN_NAME=	libgnome-shell-browser-plugin.so
WEBPLUGIN_DIR=	${PREFIX}/lib/mozilla/plugins/
WEBPLUGIN_FILES=libgnome-shell-browser-plugin.so
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c

.include <bsd.port.mk>
