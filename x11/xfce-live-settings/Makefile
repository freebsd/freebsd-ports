# New ports collection makefile for: xfce settings in live mode
# Date created:        11 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	xfce-live-settings
PORTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD xfce settings in live mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-live-settings
	${CP} -R   ${WRKSRC}/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-live-settings
.include <bsd.port.mk>
