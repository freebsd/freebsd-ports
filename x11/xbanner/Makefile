# New ports collection makefile for:	xbanner
# Date created:		13 Jan 1999
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xbanner
PORTVERSION=	1.31
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils
DISTNAME=	XBanner${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make your XDM login screen look beautiful

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
#USE_IMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/xres.c ${WRKSRC}/samples/XBanner.ad

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/XBanner.ad \
		${PREFIX}/lib/X11/app-defaults/XBanner
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/XBanner
	${INSTALL_DATA} ${WRKSRC}/QuickStart ${PREFIX}/share/doc/XBanner
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/XBanner
	@${MKDIR} ${PREFIX}/share/examples/XBanner
	${INSTALL_DATA} ${WRKSRC}/samples/_other_ideas/* \
		${PREFIX}/share/examples/XBanner
.endif

.include <bsd.port.mk>
