DISTNAME=	xview-clients
USE_IMAKE=	yes
DEPENDS=        x11/xview-lib
WRKDIR=      	../xview-lib/work/xview3.2p1-X11R6/clients
WRKSRC=      	../xview-lib/work/xview3.2p1-X11R6
NO_EXTRACT=     yes

configure: extract patch ${CONFIGURE_COOKIE}
	(cd $(WRKSRC); $(MAKE) SUBDIRS=clients Makefiles)
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

depend:
	(cd $(WRKSRC); $(MAKE) SUBDIRS=clients depend)

.include <bsd.port.mk>
