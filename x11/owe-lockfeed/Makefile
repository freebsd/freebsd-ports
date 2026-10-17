PORTNAME=	owe
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
CATEGORIES=	x11 wayland
PKGNAMESUFFIX=	-lockfeed

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Lock screen video feed QML module for the owe wallpaper engine
WWW=		https://github.com/omacom/owe

LICENSE=	MIT

USES=		cmake:testing compiler:c++17-lang gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	omacom
USE_GL=		opengl
USE_QT=		base declarative

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR=lib
CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

WRKSRC_SUBDIR=	qml-plugin

PLIST_FILES=	${QT_QMLDIR_REL}/Owe/LockFeed/libowe_lockfeed.so \
		${QT_QMLDIR_REL}/Owe/LockFeed/qmldir

.include <bsd.port.mk>
