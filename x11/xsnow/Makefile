# New ports collection makefile for:    xsnow
# Version required:     1.40
# Date created:         12 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.8 1998/10/05 05:18:03 steve Exp $
#

DISTNAME=	xsnow-1.40
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xsnow.6

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
