# New ports collection makefile for:	E-Buttons
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-buttons
PORTVERSION=	0.2
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~gahr/distfiles/
MASTER_SITE_SUBDIR=	gahr

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A simple epplet that contains several buttons used to launch programs

LIB_DEPENDS=	epplet.3:${PORTSDIR}/x11-wm/epplets

PLIST_FILES=	bin/E-Buttons.epplet

WRKSRC=		${WRKDIR}/E-buttons

USE_GL=	gl
USE_EFL=	imlib2

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lepplet -lGL -lImlib2 ${PTHREAD_LIBS}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o E-Buttons.epplet \
		${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/E-Buttons.epplet ${PREFIX}/bin

.include <bsd.port.mk>
