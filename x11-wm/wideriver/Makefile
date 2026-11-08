PORTNAME=	wideriver
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tiling window manager for the river-classic wayland compositor
WWW=		https://github.com/alex-courtis/wideriver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	river:x11-wm/river-classic

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	alex-courtis

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/wideriver \
		share/man/man1/wideriver.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
