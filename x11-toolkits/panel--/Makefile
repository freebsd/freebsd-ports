# New ports collection makefile for:    panelmm
# Date created:				28th February 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	panelmm
PORTVERSION=	0.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/panelmm

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomemm.9:${PORTSDIR}/x11-toolkits/gnome--

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
