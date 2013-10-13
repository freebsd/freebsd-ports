# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rmb
PORTVERSION=	20130510
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	LOCAL/gblach/e17/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	An e17 module to emulate right mouse button

LICENSE=	GPLv3

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	libtool_hack modarch_hack
USES=		pkgconfig

.include <bsd.port.mk>
