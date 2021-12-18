PORTNAME=	quick3d
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of controls for building complete interfaces in Qt Quick3D

LIB_DEPENDS=	libassimp.so:multimedia/assimp

USES=		compiler:c++11-lang qmake qt-dist:5
USE_QT=		core declarative gui network opengl \
		buildtools_build

QT_BINARIES=	yes

.include <bsd.port.mk>
