# New ports collection makefile for:	e17-module-uptime
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	screenshot
PORTVERSION=	20080223
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An e17 module which allows users to take screenshots

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment \
		emprint:${PORTSDIR}/x11/emprint
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment \
		emprint:${PORTSDIR}/x11/emprint

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje

.include <bsd.port.mk>
