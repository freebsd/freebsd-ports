# New ports collection makefile for:    xview-config
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.8 1997/10/28 12:28:08 tg Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-config-3.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=      	${WRKDIR}/xview3.2p1-X11R6/config
USE_IMAKE=	yes

post-extract:
	@chmod -R go+rX ${WRKDIR}

do-build:

.include <bsd.port.mk>
