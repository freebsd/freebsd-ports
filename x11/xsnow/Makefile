# New ports collection makefile for:    xsnow
# Version required:     1.39
# Date created:         12 November 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	xsnow-1.39
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/contrib/games/
DISTFILES=	xsnow-1.39.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
