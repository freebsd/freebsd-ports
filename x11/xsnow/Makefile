# New ports collection makefile for:    xsnow
# Version required:     1.40
# Date created:         12 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/12 15:22:40 asami Exp $
#

DISTNAME=	xsnow-1.40
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/contrib/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
