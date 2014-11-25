# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	everything-shotgun
PORTVERSION=	20130510
PORTREVISION=	1
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	LOCAL/gblach/e17/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	E17 shotgun plugin for the "everything" module

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2
USE_EFL=	edje libtool_hack modarch_hack

BROKEN=		Don't build with EFL 1.11
DEPRECATED=	Broken and updates aren't available
EXPIRATION_DATE=2014-12-31

.include <bsd.port.mk>
