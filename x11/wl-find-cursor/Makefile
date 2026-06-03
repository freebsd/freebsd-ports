PORTNAME=	wl-find-cursor
DISTVERSION=	g20260203
CATEGORIES=	x11 wayland

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Highlight and print out mouse position on Wayland
WWW=		https://github.com/cjacker/wl-find-cursor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USE_GITHUB=	yes
GH_ACCOUNT=	cjacker
GH_TAGNAME=	ce1a125

MAKE_ARGS=	LOCALBASE=${LOCALBASE} \
		PREFIX=${PREFIX}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
