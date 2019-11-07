# Created by: Vincent Tantardini <vinc@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	hsetroot
PORTVERSION=	1.0.3
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Wallpaper manipulation utility for X11

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2
RUN_DEPENDS=	xrandr:x11/xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	himdel

USES=		gmake pkgconfig xorg
USE_XORG=	x11

PLIST_FILES=	bin/hsetroot
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
