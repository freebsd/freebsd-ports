# $FreeBSD$

PORTNAME=	virtualkeyboard
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 Virtual Keyboard Module

USE_QT5=	core network gui widgets svg qml quick buildtools_build
QT_DIST=	${PORTNAME}

USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
