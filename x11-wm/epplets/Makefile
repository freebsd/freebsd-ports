# New ports collection makefile for:   epplets
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epplets
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://kde.planetmirror.com/pub/enlightenment/epplets/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/epplets/

DISTNAME=	epplet-base-${PORTVERSION}

MAINTAINER=	cmc@groupofnine.org

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop \
		epplet.1:${PORTSDIR}/x11-wm/libepplet
BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	import:${PORTSDIR}/graphics/ImageMagick

WRKSRC=		${WRKDIR}/Epplets-0.5

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
CONFIGURE_ENV=	EROOT=${X11BASE}/share/enlightenment \
		EBIN=${X11BASE}/bin \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		X_LIBS="-lxpg4"

.include <bsd.port.mk>
