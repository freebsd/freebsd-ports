# $FreeBSD$

PORTNAME=	quickcontrols
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of controls for building complete interfaces in Qt Quick

BROKEN_armv6=		fails to install: pkg-static: Unable to access file ApplicationWindow.qmlc: No such file or directory

USES=		compiler:c++11-lang qmake qt-dist:5,quickcontrols
USE_QT=		core declarative gui widgets \
		buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
