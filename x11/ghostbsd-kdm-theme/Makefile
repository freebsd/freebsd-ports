# New ports collection makefile for: gnome settings in live mode
# Date created:        11 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-kdm-theme
PORTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD theme for kdm and autologin too

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	kdm:x11/kde4-workspace \
		iso_to_hd:x11/ghostbsd-installed-common-settings

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/apps/kdm/themes
	${CP} -R   ${WRKSRC}/* ${STAGEDIR}/${PREFIX}/share/apps/kdm/themes/ghostbsd/
.include <bsd.port.mk>
