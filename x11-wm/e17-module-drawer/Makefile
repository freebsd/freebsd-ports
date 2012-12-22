# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drawer
PORTVERSION=	20111128
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://files.roorback.net/e17/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	An e17 module to display/organize different types of information

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment \
		ethumb:${PORTSDIR}/graphics/ethumb
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment \
		ethumb:${PORTSDIR}/graphics/ethumb

DEPRECATED=	Deprecated upstream
EXPIRATION_DATE=2013-01-31

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_EFL=	edje libtool_hack modarch_hack
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
