PORTNAME=	qhotkey
DISTVERSION=	1.5.0-7
DISTVERSIONSUFFIX=	-gcd72a01
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Global shortcut/hotkey for Desktop Qt-Applications
WWW=		https://github.com/Skycoder42/QHotkey

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}
qt5_PKGNAMESUFFIX=	-qt5
qt6_PKGNAMESUFFIX=	-qt6

USES=		cmake gl xorg
USE_GL=		gl opengl
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Skycoder42
GH_PROJECT=	QHotkey

CMAKE_ON=	BUILD_SHARED_LIBS

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		core gui x11extras qmake:build buildtools:build
CMAKE_ARGS=	-DQT_DEFAULT_MAJOR_VERSION=5
.endif

.if ${FLAVOR} == qt6
USES+=		qt:6
USE_QT=		base
CMAKE_ARGS=	-DQT_DEFAULT_MAJOR_VERSION=6
.endif

.include <bsd.port.mk>
