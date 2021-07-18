# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>

PORTNAME=	muffin
PORTVERSION=	4.8.0
PORTREVISION=	1
CATEGORIES=	x11-wm gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Compositing window manager forked from Mutter for use with Cinnamon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		gnome-autogen.sh:devel/gnome-common \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		gtkdocize:textproc/gtk-doc \
		xkeyboard-config>0:x11/xkeyboard-config
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libdrm.so:graphics/libdrm \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjson-glib-1.0.so:devel/json-glib \
		libstartup-notification-1.so:x11/startup-notification \
		libwacom.so:x11/libwacom \
		libxkbcommon.so:x11/libxkbcommon \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>0:x11/xkeyboard-config

USES=		autoreconf:build compiler:c11 gettext-tools gl gmake gnome \
		libtool localbase pathfix pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	cairo dconf gdkpixbuf2 gnomeprefix glib20 gtk30 intltool \
		introspection

USE_XORG=	ice sm x11 xcb xcomposite xcursor xdamage xext xfixes xi xinerama \
		xkbfile xrandr xrender xtst

USE_GL=		egl gbm gl

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-maintainer-flags=no
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

OPTIONS_DEFINE=		WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=	libinput.so:x11/libinput \
			libudev.so:devel/libudev-devd \
			libwayland-server.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland-egl-server

post-patch:
	@${REINPLACE_CMD} 's/--warn-error//' ${WRKSRC}/src/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh

.include <bsd.port.mk>
