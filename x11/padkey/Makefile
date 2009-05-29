# New ports collection makefile for:	padkey
# Date created:			19 Dec 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	padkey
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11 games
MASTER_SITES=	http://www.liquidx.org/padkey/releases/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use an authentic SNES controller to play games

USE_XORG=	x11 xtst

PLIST_FILES=	bin/padkey
PORTDOCS=	CREDITS README

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/|${LOCALBASE}/|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/padkey ${PREFIX}/bin/padkey
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/CREDITS ${DOCSDIR}/CREDITS
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
