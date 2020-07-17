# $FreeBSD$

PORTNAME=	nwg-launchers
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	5375b8196bfc.patch:-p1 # https://github.com/nwg-piotr/nwg-launchers/pull/69
PATCHFILES+=	2997dc9289a8.patch:-p1 # https://github.com/nwg-piotr/nwg-launchers/pull/71

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK-based launchers: application grid, button bar, dmenu for sway and other window managers

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

# XXX Remove cmake dependency after nlohmann-json adds pkg-config support
BUILD_DEPENDS=	cmake:devel/cmake \
		nlohmann-json>0:devel/nlohmann-json

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	nwg-piotr

post-patch:
# Respect PREFIX when looking for .desktop files
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' ${WRKSRC}/grid/grid_tools.cc

.include <bsd.port.mk>
