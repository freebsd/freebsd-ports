# New ports collection makefile for:	e17-module-devian
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	devian
PORTVERSION=	23062006
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	An e17 module that displays images and rss feeds

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
