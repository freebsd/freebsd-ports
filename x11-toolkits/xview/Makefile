DISTNAME=	xview3.2p1-X11R6
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/contrib/libraries/
EXTRACT_SUFX=	.tar.gz
WRKDIR=      	xview3.2p1-X11R6/config
WRKSRC=      	xview3.2p1-X11R6/config
DISTFILES=	xview3.2p1-X11R6.tar.gz

configure: extract patch ${CONFIGURE_COOKIE}
	(cd $(WRKSRC)/config; xmkmf)
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

.include <bsd.port.mk>
