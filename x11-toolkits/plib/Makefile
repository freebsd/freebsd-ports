# New ports collection makefile for:	plib
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=		plib
PORTVERSION= 		1.0.12a
CATEGORIES=		x11-toolkits
MASTER_SITES=		ftp://ftp.flightgear.org/pub/fgfs/Source/ \
			http://math.missouri.edu/~stephen/software/flightgear/
DISTFILES=		plib-1.0.12a.tar.gz calibrate-0.0.1.tar.gz

MAINTAINER=		brian@CSUA.Berkeley.EDU

LIB_DEPENDS=		GL.14:${PORTSDIR}/graphics/Mesa3 		\
			GLU.14:${PORTSDIR}/graphics/Mesa3		\
			glut.3:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS=-I${X11BASE}/include
CONFIGURE_ARGS+=	--includedir=$(PREFIX)/include/plib
USE_GMAKE=		yes
USE_NEWGCC=		yes
MANCOMPRESSED=		yes

MAN1=			calibrate.1

pre-build:
	@(cd ${WRKDIR}/calibrate-0.0.1; ${MAKE})
	@${ECHO_MSG} "${PREFIX}"

pre-install:
	@(cd ${WRKDIR}/calibrate-0.0.1; ${MAKE} PREFIX=${PREFIX} install)

.include <bsd.port.mk>
