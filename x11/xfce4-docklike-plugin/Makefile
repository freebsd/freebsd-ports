PORTNAME=	xfce4-docklike-plugin
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	laurent@FreeBSD.org
COMMENT=	Modern, minimalist taskbar for Xfce
WWW=		https://docs.xfce.org/panel-plugins/xfce4-docklike-plugin/start

LICENSE=	GPLv3

USES=		compiler:c++11-lang gettext-tools gnome meson pkgconfig tar:xz \
		xfce xorg
USE_GNOME=	gdkpixbuf gtk30
USE_XFCE=	libmenu panel windowing
USE_XORG=	x11 xi

MESON_ARGS=	-Dx11=enabled

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_MESON_ENABLED=	wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
