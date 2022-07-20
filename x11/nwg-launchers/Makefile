PORTNAME=	nwg-launchers
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f123f433ad2d.patch:-p1 # https://github.com/nwg-piotr/nwg-launchers/pull/196

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK-based launchers: application grid, button bar, dmenu for sway and other window managers

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	nwg-piotr

OPTIONS_DEFINE=	GLS
OPTIONS_DEFAULT=GLS

GLS_DESC=		Layer-shell support
GLS_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
GLS_MESON_ENABLED=	layer-shell

post-patch:
# Respect PREFIX when looking for .desktop files
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/common/nwg_classes.cc \
		${WRKSRC}/grid/grid_tools.cc

.include <bsd.port.mk>
