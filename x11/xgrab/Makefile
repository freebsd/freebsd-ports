DISTNAME=	xgrabsc.2_3
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.sunet.se/pub/X11/R5contrib/
CATEGORIES+=	x11

MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/app-defaults  -f

.include <bsd.port.mk>
