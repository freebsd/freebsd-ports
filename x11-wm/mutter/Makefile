# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	mutter
PORTVERSION=	3.28.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>=0:x11/xkeyboard-config \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libfribidi.so:converters/fribidi \
		libxkbcommon.so:x11/libxkbcommon \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libupower-glib.so:sysutils/upower \
		libjson-glib-1.0.so:devel/json-glib \
		libxkbfile.so:x11/libxkbfile \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>=0:x11/xkeyboard-config \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c++0x gettext gl gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GL=		egl
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 introspection
USE_XORG=	ice sm x11 xcb xcomposite xcursor xdamage xext xfixes \
		xi xinerama xrandr xrender xtst
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-Wno-unknown-warning-option \
		-Wno-format-nonliteral
CPPFLAGS+=	-fno-omit-frame-pointer
CONFIGURE_ARGS=	--without-libwacom \
		--disable-wayland

# Required by embedded cogl/clutter forks.
CONFIGURE_ARGS+=	--with-x \
		--with-gl-libname=libGL.so \
		--with-gles1-libname=libGLESv1_CM \
		--with-gles2-libname=libGLESv2 \
		--enable-kms-egl-platform=yes \
		--enable-xlib-egl-platform=yes \
		--disable-wayland-egl-server \
		--enable-compile-warnings=yes

INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml \
		org.gnome.mutter.wayland.gschema.xml

.include <bsd.port.mk>
