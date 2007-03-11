# New ports collection makefile for:	e17-utils
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	utils
PORTVERSION=	20070223
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-
DISTNAME=	e_${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Various supplementary utilities for e17 window manager

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel

DATADIR=	${PREFIX}/share/e_utils

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	imlib2 evas edje ecore embryo eet ewl engrave epsilon
USE_EFL_ESMART=	trans_x11

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
