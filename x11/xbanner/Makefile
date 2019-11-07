# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	xbanner
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SUNSITE/X11/xutils
DISTNAME=	XBanner${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make your XDM login screen look beautiful

USES=		xorg
USE_XORG=	x11 xpm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/xres.c ${WRKSRC}/samples/XBanner.ad

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/XBanner.ad \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XBanner

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/XBanner
	${INSTALL_DATA} ${WRKSRC}/QuickStart ${STAGEDIR}${PREFIX}/share/doc/XBanner
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${PREFIX}/share/doc/XBanner
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/XBanner
	${INSTALL_DATA} ${WRKSRC}/samples/_other_ideas/* \
		${STAGEDIR}${PREFIX}/share/examples/XBanner

.include <bsd.port.mk>
