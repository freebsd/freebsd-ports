DISTNAME=	xview-clients
DEPENDS=        ../xview-lib
WRKDIR=      	../xview-config/work/xview3.2p1-X11R6/clients
WRKSRC=      	../xview-config/work/xview3.2p1-X11R6/clients
NO_EXTRACT=     yes
PREFIX=		${X11BASE}
#USE_IMAKE=	yes

depend:
	(cd $(WRKSRC)/..; $(MAKE) SUBDIRS=clients depend)

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
