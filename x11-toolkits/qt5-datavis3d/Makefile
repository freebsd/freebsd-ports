# $FreeBSD$

PORTNAME=	datavis3d
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 3D data visualization module

USE_QT=		core declarative network gui widgets designer buildtools_build

USES=		compiler:c++11-lang qmake qt-dist:5,datavis3d
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
