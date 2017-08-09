# New ports collection makefile for: ghostbsd common settings in installed mode
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-installed-common-settings
PORTVERSION=	4.4
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD common settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

RUN_DEPENDS= dpkg:archivers/dpkg

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/sounds
	${CP} -R   ${WRKSRC}/local/* ${STAGEDIR}/${PREFIX}
.include <bsd.port.mk>
