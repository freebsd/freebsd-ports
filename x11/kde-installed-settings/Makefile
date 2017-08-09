# New ports collection makefile for: kde settings in installed mode
# Date created:        4 Jan 2016
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	kde-installed-settings
PORTVERSION=	1.11
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD KDE settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	dpkg:archivers/dpkg \
		iso_to_hd:x11/ghostbsd-installed-common-settings

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/kde-settings/etc
	${CP} -Rf   ${WRKSRC}/etc ${STAGEDIR}/${PREFIX}/share/ghostbsd/kde-settings
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/apps
	${CP} -Rf   ${WRKSRC}/share/apps/* ${STAGEDIR}/${PREFIX}/share/apps
.include <bsd.port.mk>
