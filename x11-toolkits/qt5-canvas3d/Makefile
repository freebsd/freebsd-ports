# $FreeBSD$

PORTNAME=	canvas3d
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt canvas3d module

USE_QT=		core declarative gui network buildtools_build
USES=		compiler:c++11-lang qmake qt-dist:5,canvas3d

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
