# New ports collection makefile for:	xview-clients
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id$
#

DISTNAME=	xview-clients
PKGNAME=	xview-clients-3.2.1

DEPENDS=        ../xview-lib
WRKDIR=      	../xview-config/work/xview3.2p1-X11R6/clients
WRKSRC=      	../xview-config/work/xview3.2p1-X11R6/clients
NO_EXTRACT=     yes
PREFIX=		${X11BASE}
#USE_IMAKE=	yes

fetch:

depend:
	(cd $(WRKSRC)/..; $(MAKE) SUBDIRS=clients depend)

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
