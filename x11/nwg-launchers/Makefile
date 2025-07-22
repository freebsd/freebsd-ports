PORTNAME=	nwg-launchers
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1.1
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GTK-based launchers: application grid, button bar, dmenu for sway and other window managers
WWW=		https://github.com/nwg-piotr/nwg-launchers

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	nwg-piotr

OPTIONS_DEFINE=	WAYLAND
OPTIONS_DEFAULT=WAYLAND

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_MESON_ENABLED=	layer-shell

post-patch:
# Respect PREFIX when looking for .desktop files
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/common/nwg_classes.cc \
		${WRKSRC}/grid/grid_tools.cc

.include <bsd.port.mk>
