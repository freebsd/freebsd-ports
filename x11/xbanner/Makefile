# New ports collection makefile for:	xbanner
# Version required:	1.31
# Date created:		13 Jan 1999
# Whom:			giffunip@asme.org
#
# $Id:  Exp $
#

DISTNAME=	XBanner1.31
PKGNAME=	xbanner-1.31
CATEGORIES=	x11
MASTER_SITES=	ftp://physics.fullerton.edu/pub/Linux/XBanner/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=X11/xutils

MAINTAINER=     ports@FreeBSD.ORG

USE_X_PREFIX=	yes
#USE_IMAKE=	yes

post-install:
	${INSTALL_DATA}	${WRKSRC}/samples/XBanner.ad \
	$(X11BASE)/lib/X11/app-defaults/XBanner
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/XBanner
	$(CP) ${WRKSRC}/QuickStart ${PREFIX}/share/doc/XBanner
	${CP} ${WRKSRC}/docs/* ${PREFIX}/share/doc/XBanner
	${MKDIR} ${PREFIX}/share/examples/XBanner
	$(CP) ${WRKSRC}/samples/_other_ideas/* ${PREFIX}/share/examples/XBanner
.endif

.include <bsd.port.mk>
