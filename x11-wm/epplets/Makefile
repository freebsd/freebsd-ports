# New ports collection makefile for:   epplets
# Version required:    0.3
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Epplets-0.3
PKGNAME=	epplets-0.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.eterm.org/download/

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
CONFIGURE_ENV=	EROOT=${X11BASE}/share/enlightenment \
		EBIN=${X11BASE}/bin

.include <bsd.port.mk>
