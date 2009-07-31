# New ports collection makefile for:	e17-module-deskshow
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	deskshow
PORTVERSION=	20080223
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	E17 module that minimizes all windows to show the desktop

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje

.include <bsd.port.mk>
