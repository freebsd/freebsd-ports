# New ports collection makefile for:	plib
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	plib
PORTVERSION=	1.8.4
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A portable library for joystick/sound/OpenGL GUI/3D math

USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CXXFLAGS+=	-fPIC
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${X11BASE}/lib ${PTHREAD_LIBS}"

post-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/plib-jscal ${FILESDIR}/jsBSDCal.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/plib-jscal ${PREFIX}/bin

.include <bsd.port.mk>
