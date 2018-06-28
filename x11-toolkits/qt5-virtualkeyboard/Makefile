# $FreeBSD$

PORTNAME=	virtualkeyboard
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 Virtual Keyboard Module

USE_QT=		core network gui widgets svg qml quick buildtools_build

USES=		qmake qt-dist:5,virtualkeyboard
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
