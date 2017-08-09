# New ports collection makefile for: ghostbsd ksplash theme
# Date created:        11 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-ksplash-theme
PORTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD theme for ksplash

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	/usr/local/share/apps/ksplash/Themes/Default/Theme.rc:x11-themes/kde4-base-artwork \
		iso_to_hd:x11/ghostbsd-installed-common-settings

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/apps/ksplash/Themes
	${CP} -R  ${WRKSRC}/Themes/* ${STAGEDIR}/${PREFIX}/share/apps/ksplash/Themes/
.include <bsd.port.mk>
