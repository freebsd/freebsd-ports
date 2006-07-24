# New ports collection makefile for:	e17-module-engage
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	engage
PORTVERSION=	20060719
CATEGORIES=	x11
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Alternative e17 application launcher with tray support

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel
LIB_DEPENDS=	esmart_trans_x11.0:${PORTSDIR}/graphics/esmart
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB+=	MODULE_ARCH=freebsd${OSREL}-${ARCH}

.include <bsd.port.mk>
