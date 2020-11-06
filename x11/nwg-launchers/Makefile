# $FreeBSD$

PORTNAME=	nwg-launchers
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK-based launchers: application grid, button bar, dmenu for sway and other window managers

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	nwg-piotr

post-patch:
# Respect PREFIX when looking for .desktop files
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/common/nwg_tools.cc \
		${WRKSRC}/grid/grid_tools.cc

.include <bsd.port.mk>
