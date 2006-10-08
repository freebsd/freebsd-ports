# New ports collection makefile for:	e17-module-mixer
# Date created:		30 September 2006
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mixer
PORTVERSION=	20060926
CATEGORIES=	x11
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An e17 module to adjust audio mixer settings

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
