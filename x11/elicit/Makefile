# New ports collection makefile for:	elicit
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	elicit
PORTVERSION=	20060719
CATEGORIES=	x11
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Screen zoomer/color picker for e17

LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore \
		edb.1:${PORTSDIR}/databases/edb \
		edje.5:${PORTSDIR}/graphics/edje \
		eet.9:${PORTSDIR}/devel/eet \
		esmart_trans_x11.0:${PORTSDIR}/graphics/esmart \
		evas.1:${PORTSDIR}/graphics/evas \
		Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
