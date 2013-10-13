# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	engage
PORTVERSION=	20130510
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	LOCAL/gblach/e17/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	MacOS X like taskbar module for e17

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	edje libtool_hack modarch_hack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
