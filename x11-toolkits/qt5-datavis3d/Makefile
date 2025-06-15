PORTNAME=	datavis3d
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 3D data visualization module

USE_PERL5=	build
USE_QT=		core declarative network gui widgets designer buildtools:build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,datavis3d

.include <bsd.port.mk>
