# $FreeBSD$

PORTNAME=	quicktimeline
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of controls for building complete interfaces in Qt Quick Timeline

USES=		compiler:c++11-lang qmake qt-dist:5
USE_QT=		core declarative quickcontrols \
		buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
