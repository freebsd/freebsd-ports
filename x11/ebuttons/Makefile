# New ports collection makefile for:	E-Buttons 0.2
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-buttons
PORTVERSION=	0.2
CATEGORIES=	x11
MASTER_SITES=	http://www.moodfarm.demon.co.uk/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhb@FreeBSD.org

LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/epplets

WRKSRC=		${WRKDIR}/E-buttons

USE_X_PREFIX=	yes

pre-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

pre-build:
	@(cd ${WRKSRC} && ${MAKE} clean)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/E-Buttons.epplet ${PREFIX}/bin

.include <bsd.port.mk>
