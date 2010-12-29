# New ports collection makefile for:	e17-module-deskshow
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	deskshow
PORTVERSION=	20101003
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://files.roorback.net/e17/2010-10-03/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	E17 module that minimizes all windows to show the desktop

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje libtool_hack modarch_hack

.include <bsd.port.mk>
