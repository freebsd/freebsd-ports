# $FreeBSD$

PORTNAME=	gamepad
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 Gamepad Module

USE_QT=		core declarative gui buildtools_build

USES=		compiler:c++11-lang qmake:norecursive qt-dist:5,gamepad
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
