# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	verve-plugin
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A command line plugin for Xfce4

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 intltool intlhack
USE_XFCE=	configenv panel libexo libgui libutil
USE_PKGCONFIG=	build

CONFIGURE_ARGS=	--disable-debug

OPTIONS_DEFINE=	NLS DBUS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.include <bsd.port.post.mk>
