PORTNAME=	libxfce4windowing
DISTVERSION=	4.20.4
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

MESON_ARGS=	-Dx11=enabled

OPTIONS_DEFINE=		DOCS GIR NLS VAPI WAYLAND
OPTIONS_DEFAULT=	GIR VAPI WAYLAND
OPTIONS_SUB=		yes

GIR_DESC=	GObject Introspection support

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk-doc

GIR_USE=	GNOME=introspection:build
GIR_MESON_TRUE=	introspection

NLS_USES=	gettext-runtime

VAPI_USES=		vala:build
VAPI_MESON_ENABLED=	vala

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_RUN_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_MESON_ENABLED=	wayland

post-patch:
	@${CP} ${FILESDIR}/libxfce4windowing-docs.xml.in ${WRKSRC}/docs/reference/libxfce4windowing
	@${CP} ${FILESDIR}/libxfce4windowingui-docs.xml.in ${WRKSRC}/docs/reference/libxfce4windowingui

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
