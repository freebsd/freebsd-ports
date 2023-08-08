PORTNAME=	libclipboard
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight cross-platform clipboard library
WWW=		https://jtanx.github.io/libclipboard/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig xorg
USE_XORG=	xcb
USE_GITHUB=	yes
GH_ACCOUNT=	jtanx

CMAKE_ON=	BUILD_SHARED_LIBS LIBCLIPBOARD_ADD_SOVERSION

.include <bsd.port.mk>
