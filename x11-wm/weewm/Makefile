# New ports collection makefile for: weewm
# Date created:        15 May 2003
# Whom:                Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
#
# $FreeBSD$
#

PORTNAME=	weewm
PORTVERSION=	0.01
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.weewm.org/download/

MAINTAINER=	ppl@nbnet.nb.ca
COMMENT=	Fast and ultra light windowmanager with total keyboard control

USE_X_PREFIX=	yes

WRKSRC=${WRKDIR}/weewm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/weewm ${PREFIX}/bin

.include <bsd.port.mk>
