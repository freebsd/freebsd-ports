# New ports collection makefile for:	e17-module-devian
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	devian
PORTVERSION=	20060926
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An e17 module that displays images and rss feeds

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje

BROKEN=		doesn't compile with recent e17
DEPRECATED=	abandoned by developer
EXPIRATION_DATE=	2008-03-20

.include <bsd.port.mk>
