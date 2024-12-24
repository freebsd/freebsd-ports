PORTNAME=	libxfce4windowing
DISTVERSION=	4.20.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Windowing concept abstraction library for X11 and Wayland
WWW=		https://gitlab.xfce.org/xfce/libxfce4windowing

LICENSE=	GPLv2

LIB_DEPENDS=	libdisplay-info.so:sysutils/libdisplay-info

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bz2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libwnck3
USE_LDCONFIG=	yes
USE_XFCE=	xdt
USE_XORG=	x11 xrandr

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS GIR NLS WAYLAND
OPTIONS_DEFAULT=	GIR WAYLAND
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	gtk-doc-html

GIR_DESC=	GObject Introspection support
GIR_USE=	GNOME=introspection:build
GIR_MESON_TRUE=	introspection

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=wayland

.include <bsd.port.mk>
