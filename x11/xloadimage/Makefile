DISTNAME=	xloadimage
DISTFILES=	xloadimage.3.03.tar.Z
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/X11-contrib/
CATEGORIES+=	x11
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults -f
MAINTAINER=	jmz@FreeBSD.org

pre-install:
	@mkdir -p ${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
