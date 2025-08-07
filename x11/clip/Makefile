PORTNAME=	clip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	x11
PKGNAMESUFFIX=	-clipboard-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform C++ library to copy/paste clipboard content
WWW=		https://github.com/dacap/clip

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		cmake:testing localbase:ldflags xorg
USE_XORG=	xcb
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dacap

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	CLIP_EXAMPLES CLIP_TESTS
CMAKE_TESTING_ON=	CLIP_TESTS

# tests as of 1.10: 0% tests passed, 3 tests failed out of 3, see https://github.com/dacap/clip/issues/87

.include <bsd.port.mk>
