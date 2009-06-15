# New ports collection makefile for:	e17-module-bling
# Date created:		13 April 2008
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bling
PORTVERSION=	20080413
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	E17 composite manager module

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje
USE_XORG=	xcomposite xext xrender xdamage xfixes

.include <bsd.port.mk>
