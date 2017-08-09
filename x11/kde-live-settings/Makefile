# New ports collection makefile for: kde settings in live mode
# Date created:        4 jan 2016
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	kde-live-settings
PORTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD kde settings in live mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/config
	${CP} -R   ${WRKSRC}/share/config/* ${STAGEDIR}/${PREFIX}/share/config
.include <bsd.port.mk>
