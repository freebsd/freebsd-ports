# New ports collection makefile for:	e17-utils
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	utils
PORTVERSION=	20060719
CATEGORIES=	x11-wm
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	e17-
DISTNAME=	e_${PORTNAME}-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Various supplementary utilities for e17 window manager

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel
LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		evas.1:${PORTSDIR}/graphics/evas \
		edje.5:${PORTSDIR}/graphics/edje \
		ecore.1:${PORTSDIR}/x11/ecore \
		embryo.9:${PORTSDIR}/lang/embryo \
		eet.9:${PORTSDIR}/devel/eet \
		ewl.0:${PORTSDIR}/x11-toolkits/ewl \
		engrave.1:${PORTSDIR}/devel/engrave \
		epsilon.0:${PORTSDIR}/graphics/epsilon \
		esmart_trans_x11.0:${PORTSDIR}/graphics/esmart
RUN_DEPENDS=	${BUILD_DEPENDS}

DATADIR=	${PREFIX}/share/e_utils

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
