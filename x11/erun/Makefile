# New ports collection makefile for:	E-Run 1.2
# Date created:				17 June 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	E-Run
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kbyanc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple epplet for launching arbitrary programs

LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/libepplet

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes

CPPFLAGS=	-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${X11BASE}/lib -lepplet ${PTHREAD_LIBS}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME}.epplet \
		${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.epplet ${PREFIX}/bin

.include <bsd.port.mk>
