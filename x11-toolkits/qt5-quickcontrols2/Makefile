# $FreeBSD$

PORTNAME=	quickcontrols2
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of controls for building complete interfaces in Qt Quick

USES=		qmake:norecursive qt-dist:5
USE_QT=		core gui qml quick widgets \
		buildtools_build
QT_DIST=	${PORTNAME}
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
