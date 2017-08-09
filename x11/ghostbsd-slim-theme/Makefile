# New ports collection makefile for: gnome settings in live mode
# Date created:        11 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-slim-theme
PORTVERSION=	1.2
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD theme for slim and autologin too

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	slim:x11/slim \

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/slim/themes/ghostbsd
	${CP} -R ${WRKSRC}/gbsd/* ${STAGEDIR}/${PREFIX}/share/slim/themes/ghostbsd/
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/slim/etc
	${CP} -R ${WRKSRC}/etc/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/slim/etc/
.include <bsd.port.mk>
