# New ports collection makefile for:	libxfce4menu
# Date created:		7 Oktober 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxfce4menu
PORTVERSION=	4.8.1
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/libxfce4ui/${PORTVERSION:R}
DISTNAME=	libxfce4ui-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 library for a freedesktop.org compliant menu implementation

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil xfconf

OPTIONS=	APIDOCS	"Install api documentation"	off \
		NLS	"Enable Native Language Support"	on \
		STARTUP	"Enable startup notification"	on \
		GLADEUI	"Enable Glade interface designer support"	off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_APIDOCS)
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if !defined(WITHOUT_GLADEUI)
LIB_DEPENDS+=	gladeui-1.10:${PORTSDIR}/devel/glade3
CONFIGURE_ARGS+=--enable-gladeui
.else
CONFIGURE_ARGS+=--disable-gladeui
.endif

.include <bsd.port.post.mk>
