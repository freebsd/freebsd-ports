# New ports collection makefile for:	verve plugin for xfce4
# Date created:				11 September 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	verve-plugin
PORTVERSION=	1.0.0
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A command line plugin for xfce4

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel libexo libgui libutil

CONFIGURE_ARGS=	--disable-debug

OPTIONS=	NLS "Enable Native Language Support" on \
		DBUS "Enable D-BUS support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.include <bsd.port.post.mk>
