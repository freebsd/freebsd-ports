# $FreeBSD$

PORTNAME=	canvas3d
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt canvas3d module

USE_QT5=	core gui network qml quick buildtools_build
QT_DIST=	${PORTNAME}
USES=		qmake

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
