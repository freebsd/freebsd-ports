DISTNAME=	xsnow-1.39
DISTFILES=	xsnow-1.39.tar.Z
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/contrib/games/

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
