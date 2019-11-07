# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	perwindowlayoutd
PORTVERSION=	0.6
CATEGORIES=	x11
MASTER_SITES=	SF/perwindowlayout

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Keeps per-window keyboard layout under X11

LICENSE=	GPLv3

USES=		localbase xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11

PLIST_FILES=	bin/perWindowLayoutD
PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
