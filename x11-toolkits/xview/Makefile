# New ports collection makefile for:    xview-config
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.5 1995/04/12 15:22:43 asami Exp $
#

DISTNAME=	xview-config
PKGNAME=	xview-config-3.2.1
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/contrib/libraries/
DISTFILES=	xview3.2p1-X11R6.tar.gz

WRKSRC=      	${WRKDIR}/xview3.2p1-X11R6/config
USE_IMAKE=	yes

post-extract:
	@chmod -R go+rX ${WRKDIR}

do-build:

.include <bsd.port.mk>
