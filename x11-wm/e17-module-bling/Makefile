# New ports collection makefile for:	e17-module-bling
# Date created:		13 April 2008
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bling
PORTVERSION=	20080413
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	E17 composite manager module

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje libtool_hack modarch_hack
USE_XORG=	xcomposite xext xrender xdamage xfixes

BROKEN=		does not compile
DEPRECATED=	abandoned upstream
EXPIRATION_DATE=	2011-01-01

.include <bsd.port.mk>
