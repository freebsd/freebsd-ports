# $FreeBSD$

PORTNAME=	quick
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

USE_QT5=	core gui network qml sql testlib \
		widgets xmlpatterns buildtools_build
QT_DIST=	declarative
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

.include <bsd.port.mk>
