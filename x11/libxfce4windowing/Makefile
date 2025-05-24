PORTNAME=	libxfce4windowing
DISTVERSION=	4.20.3
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Windowing concept abstraction library for X11 and Wayland
WWW=		https://gitlab.xfce.org/xfce/libxfce4windowing

LICENSE=	GPLv2

LIB_DEPENDS=	libdisplay-info.so:sysutils/libdisplay-info

USES=		gettext-tools gnome meson pkgconfig python:build shebangfix \
		tar:bz2 xfce xorg
USE_GNOME=	glib20 gtk30 libwnck3
USE_LDCONFIG=	yes
USE_XFCE=	xdt
USE_XORG=	x11 xrandr
SHEBANG_FILES=	xdt-gen-visibility

MESON_ARGS=	-Dgtk-doc=false \
		-Dx11=enabled

OPTIONS_DEFINE=		GIR NLS WAYLAND
OPTIONS_DEFAULT=	GIR WAYLAND
OPTIONS_SUB=		yes

GIR_DESC=	GObject Introspection support

# At present gtk-doc is broken due to missing files in the distribution
#DOCS_MESON_TRUE=	gtk-doc

GIR_USE=	GNOME=introspection:build
GIR_MESON_TRUE=	introspection

NLS_USES=	gettext-runtime

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_RUN_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_ENABLED=	wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
