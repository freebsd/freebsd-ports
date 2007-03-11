# New ports collection makefile for:	ecore
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	20070223
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A core event abstraction library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas
USE_LDCONFIG=	yes
USE_GETOPT_LONG=yes

CONFIGURE_ARGS=	--disable-ecore-dfb

OPTIONS=	DBUS		"Enable DBUS support" on \
		CURL		"Enable Curl support" on \
		X11		"Enable X11 support" on \
		EVAS		"Enable evas support" on \
		EET		"Enable EET configs support" on
#		OPENSSL		"Enable OpenSSL support" on \
#		DIRECTFB	"Enable DirectFB support" off \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--enable-ecore-x
USE_XLIB=		yes
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--disable-ecore-x
PLIST_SUB+=		X11="@comment "
.endif

.if !defined(WITHOUT_EVAS)
CONFIGURE_ARGS+=	--enable-ecore-evas
USE_EFL+=		evas
PLIST_SUB+=		EVAS=""
.else
CONFIGURE_ARGS+=	--disable-ecore-evas
PLIST_SUB+=		EVAS="@comment "
.endif

.if !defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=		curl.4:${PORTSDIR}/ftp/curl
PLIST_SUB+=		CURL=""
.else
CONFIGURE_ARGS+=	--disable-curl
PLIST_SUB+=		CURL="@comment "
.endif

#.if !defined(WITHOUT_OPENSSL)
#CONFIGURE_ARGS+=	--enable-openssl
#PLIST_SUB+=		OPENSSL=""
#USE_OPENSSL=		yes
#.else
#CONFIGURE_ARGS+=	--disable-openssl
#PLIST_SUB+=		OPENSSL="@comment "
#.endif

.if defined(WITH_DBUS)
CONFIGURE_ARGS+=	--enable-ecore-dbus
PLIST_SUB+=		DBUS=""
.else
CONFIGURE_ARGS+=	--disable-ecore-dbus
PLIST_SUB+=		DBUS="@comment "
.endif

#.if defined(WITH_DIRECTFB)
#CONFIGURE_ARGS+=	--enable-ecore-dfb
#PLIST_SUB+=		DIRECTFB=""
#LIB_DEPENDS+=		directfb-0.9.16:${PORTSDIR}/devel/directfb
#.else
#CONFIGURE_ARGS+=	--disable-ecore-dfb
#PLIST_SUB+=		DIRECTFB="@comment "
#.endif

.if !defined(WITHOUT_EET)
CONFIGURE_ARGS+=	--enable-ecore-config
USE_EFL+=		eet
PLIST_SUB+=		EET=""
.else
CONFIGURE_ARGS+=	--disable-ecore-config
PLIST_SUB+=		EET="@comment "
.endif

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
