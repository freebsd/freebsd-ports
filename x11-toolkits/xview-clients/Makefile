# New ports collection makefile for:	xview-clients
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.7 1995/04/25 04:47:41 asami Exp $
#

DISTNAME=	xview-clients
PKGNAME=	xview-clients-3.2.1
CATEGORIES=	x11

DEPENDS=        ${PORTSDIR}/x11/xview-lib
WRKSRC=      	${PORTSDIR}/x11/xview-config/work/xview3.2p1-X11R6/clients
NO_WRKDIR=	yes
NO_EXTRACT=     yes
PREFIX=		${X11BASE}
#USE_IMAKE=	yes

do-fetch:

post-configure:
	(cd $(WRKSRC)/..; $(MAKE) SUBDIRS=clients depend)

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
