# New ports collection makefile for:	E-FancyLauncher
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-FancyLauncher
PORTVERSION=	0.7
CATEGORIES=	x11
MASTER_SITES=	http://user.it.uu.se/~adavid/Epplets/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhb@FreeBSD.org

LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/epplets	# XXX

WRKSRC=		${WRKDIR}/E-FancyLauncher

USE_GMAKE=	yes
USE_X_PREFIX=	yes

ALL_TARGET=	clean all

post-patch:
	( cd ${WRKSRC} ; ${MV} makefile Makefile )

.include <bsd.port.mk>
