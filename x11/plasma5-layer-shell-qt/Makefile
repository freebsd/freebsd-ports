PORTNAME=	layer-shell-qt
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt component to make use of the Wayland wl-layer-shell protoco
WWW=		https://kde.org/

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gettext gl kde:5 pkgconfig qt:5 tar:xz
USE_GL=		gl
USE_KDE=	ecm
USE_QT=		core gui wayland \
		buildtools_build qmake_build

.include <bsd.port.mk>
