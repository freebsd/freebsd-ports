# New ports collection makefile for:	e17-module-xkbswitch
# Date created:		21 April 2012
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	xkbswitch
PORTVERSION=	20111128
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://files.roorback.net/e17/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	magik@roorback.net
COMMENT=	X keyboard switcher module for Enlightenment 0.17

LIB_DEPENDS=	xkbfile.1:${PORTSDIR}/x11/libxkbfile
BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_EFL=	edje libtool_hack modarch_hack

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
