# New ports collection makefile for:	winselector
# Date created:		2006-08-15
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	winselector
PORTVERSION=	20080223
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An e17 module to switch between windows

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnometarget
USE_EFL=	edje

.include <bsd.port.mk>
