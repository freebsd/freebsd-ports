# $FreeBSD$

PORTNAME=	kwayland-server
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Wayland Server Components built on KDE Frameworks

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	plasma-wayland-protocols>=0:x11/plasma-wayland-protocols \
		wayland-protocols>=1.14:graphics/wayland-protocols
RUN_DEPENDS=	plasma-wayland-protocols>=0:x11/plasma-wayland-protocols

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm wayland
USE_QT=		concurrent gui wayland \
		buildtools_build qmake_build

.include <bsd.port.mk>
