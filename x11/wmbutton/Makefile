# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmbutton
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://greek0.net/wmbutton/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays 9 buttons to run apps of your choice

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	xpm

SUB_FILES=	pkg-message

PORTDOCS=	README
PORTEXAMPLES=	dot.wmbutton
PLIST_FILES=	bin/wmbutton

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} \
		-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include \
		wmb_libs.c wmbutton.c -o wmbutton \
		-L${LOCALBASE}/lib -lXpm -lXext -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbutton ${STAGEDIR}${PREFIX}/bin/wmbutton

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmbutton ${STAGEDIR}${EXAMPLESDIR}/dot.wmbutton

.include <bsd.port.mk>
