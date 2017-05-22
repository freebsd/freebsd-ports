# $FreeBSD$

PORTNAME=	declarative
DISTVERSION=	5.5.1  # QtQuick1 was last released with Qt 5.5.
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4-compatible declarative UI framework

DEPRECATED=		Has not been released since Qt 5.5 -- installation can lead to runtime conflicts with qt5-quick
EXPIRATION_DATE=	2017-06-30

DISTINFO_FILE=	${MASTERDIR}/distinfo
QT5_VERSION=	${DISTVERSION}

USE_QT5=	core designer gui network opengl script sql webkit \
		widgets xmlpatterns buildtools_build
QT_DIST=	quick1
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

# qt5logo.png is installed by qt5-widgets.
DESKTOP_ENTRIES="Qt 5 QML viewer" "" \
		"${PREFIX}/share/pixmaps/qt5logo.png" \
		"${PREFIX}/${QT_BINDIR_REL}/qmlviewer" \
		"Development;Qt;" true

.include <bsd.port.mk>
