DISTNAME=	xview-clients
DEPENDS=        ../xview-lib
WRKDIR=      	../xview-config/work/xview3.2p1-X11R6/clients
WRKSRC=      	../xview-config/work/xview3.2p1-X11R6/clients
NO_EXTRACT=     yes

depend:
	(cd $(WRKSRC)/..; $(MAKE) SUBDIRS=clients depend)

.include <bsd.port.mk>
