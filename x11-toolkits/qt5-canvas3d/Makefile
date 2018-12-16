# $FreeBSD$

PORTNAME=	canvas3d
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt canvas3d module

USES=		compiler:c++11-lang qmake qt-dist:5,canvas3d
USE_QT=		core declarative gui network buildtools_build

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
