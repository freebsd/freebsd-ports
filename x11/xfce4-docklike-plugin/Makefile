PORTNAME=	xfce4-docklike-plugin
PORTVERSION=	0.5.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	bsd@quentb.com
COMMENT=	Modern, minimalist taskbar for Xfce
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-docklike-plugin

LICENSE=	GPLv3

USES=		gettext-tools gnome meson pkgconfig tar:xz xfce xorg
USE_GNOME=	gdkpixbuf gtk30
USE_XFCE=	libmenu panel windowing
USE_XORG=	x11

MESON_ARGS=	-Dx11=enabled

OPTIONS_DEFINE=	NLS WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_MESON_ENABLED=	wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
