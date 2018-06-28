# $FreeBSD$

PORTNAME=	gamepad
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 Gamepad Module

USE_QT=		core gui qml quick buildtools_build

USES=		qmake:norecursive qt-dist:5,gamepad
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
