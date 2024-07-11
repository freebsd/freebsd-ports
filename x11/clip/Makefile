PORTNAME=	clip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9
CATEGORIES=	x11
PKGNAMESUFFIX=	-clipboard-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform C++ library to copy/paste clipboard content
WWW=		https://github.com/dacap/clip

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dacap

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	CLIP_EXAMPLES CLIP_TESTS

PLIST_FILES=	include/clip.h \
		lib/libclip.so

do-install: # workaround for https://github.com/dacap/clip/issues/77
	${INSTALL_DATA} ${WRKSRC}/clip.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILD_WRKSRC}/libclip.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
