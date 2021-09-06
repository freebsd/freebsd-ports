PORTNAME=	layer-shell-qt
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt component to make use of the Wayland wl-layer-shell protoco

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gettext kde:5 pkgconfig qt:5 \
		tar:xz
USE_KDE=	ecm
USE_QT=		core wayland \
		buildtools_build qmake_build

.include <bsd.port.mk>
