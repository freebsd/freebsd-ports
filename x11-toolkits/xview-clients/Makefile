# New ports collection makefile for:	xview-clients
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.8 1995/05/03 02:22:33 asami Exp $
#

DISTNAME=	xview-clients
PKGNAME=	xview-clients-3.2.1
CATEGORIES=	x11

DEPENDS=        ${PORTSDIR}/x11/xview-lib
WRKSRC=      	${PORTSDIR}/x11/xview-config/work/xview3.2p1-X11R6/clients
NO_WRKDIR=	yes
NO_EXTRACT=     yes
USE_X11=	yes

do-fetch:

post-configure:
	(cd $(WRKSRC)/..; $(MAKE) SUBDIRS=clients depend)

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
