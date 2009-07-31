# New ports collection makefile for:	E-Run 1.2
# Date created:				17 June 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	E-Run
PORTVERSION=	1.2
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kbyanc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A simple epplet for launching arbitrary programs

LIB_DEPENDS=	epplet.3:${PORTSDIR}/x11-wm/epplets

PLIST_FILES=	bin/E-Run.epplet

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GL=	gl
USE_EFL=	imlib2
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lepplet -lImlib2 -lGL ${PTHREAD_LIBS}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME}.epplet \
		${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.epplet ${PREFIX}/bin

.include <bsd.port.mk>
