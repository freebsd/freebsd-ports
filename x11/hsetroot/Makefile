PORTNAME=	hsetroot
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Wallpaper manipulation utility for X11
WWW=		https://github.com/himdel/hsetroot

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	himdel

USES=		gmake pkgconfig xorg
USE_XORG=	x11 xinerama

PLIST_FILES=	bin/hsetroot bin/hsr-outputs
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
