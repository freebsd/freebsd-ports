# New ports collection makefile for:	e17-module-drawer
# Date created:		29 August 2010
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	drawer
PORTVERSION=	20110129
PORTREVISION=	1
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://files.roorback.net/e17/2011-01-29/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	magik@roorback.net
COMMENT=	An e17 module to display/organize different types of information

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment \
		ethumb:${PORTSDIR}/graphics/ethumb
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment \
		ethumb:${PORTSDIR}/graphics/ethumb

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	edje libtool_hack modarch_hack

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
