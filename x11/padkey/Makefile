# New ports collection makefile for:	padkey
# Date created:			19 Dec 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	padkey
PORTVERSION=	0.2
CATEGORIES=	x11 games
MASTER_SITES=	http://www.liquidx.org/padkey/releases/dist/

MAINTAINER=	tlp@liquidx.org
COMMENT=	Use an authentic SNES controller to play games

USE_GZIP=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes

.if defined(NOPORTDOCS)
PLIST_FILES=	bin/padkey
.else
PLIST_FILES=	bin/padkey %%DOCSDIR%%/CREDITS %%DOCSDIR%%/README
PLIST_DIRS=	%%DOCSDIR%%
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/|${X11BASE}/|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/padkey ${PREFIX}/bin/padkey
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/CREDITS ${DOCSDIR}/CREDITS
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
