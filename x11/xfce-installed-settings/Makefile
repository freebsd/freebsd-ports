# New ports collection makefile for: xfce settings in installed mode
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	xfce-installed-settings
PORTVERSION=	2.7
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD xfce settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/skel
	${CP} -R   ${WRKSRC}/etc/skel/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/skel
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/default/grub.d
	${CP} -R   ${WRKSRC}/etc/default/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/default
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/xdg
	${CP} -R   ${WRKSRC}/etc/xdg/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/xdg
.include <bsd.port.mk>
