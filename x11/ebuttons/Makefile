# New ports collection makefile for:	E-Buttons
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-buttons
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.moodfarm.demon.co.uk/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple epplet that contains several buttons used to launch programs

LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/libepplet

WRKSRC=		${WRKDIR}/E-buttons

USE_X_PREFIX=	yes

CPPFLAGS=	-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${X11BASE}/lib -lepplet ${PTHREAD_LIBS}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o E-Buttons.epplet \
		${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/E-Buttons.epplet ${PREFIX}/bin

.include <bsd.port.mk>
