# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e-module-penguins
PORTVERSION=	20140911
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	LOCAL/gblach/enlightenment/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment module that displays penguins on your desktop

BUILD_DEPENDS=	enlightenment:x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:x11-wm/enlightenment

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig tar:xz
INSTALL_TARGET=	install-strip

BROKEN=		Not compatible with Enlightenment 0.20
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

.include "../enlightenment/Makefile.plist"

OPTIONS_DEFINE=	NLS

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
