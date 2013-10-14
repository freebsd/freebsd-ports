# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxfce4menu
PORTVERSION=	4.10.0
PORTREVISION=	4
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	libxfce4ui-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Widgets library for the Xfce desktop environment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil xfconf
INSTALLS_ICONS=	yes
USES=		pathfix pkgconfig gmake

CONFIGURE_ARGS=	--with-vendor-info=FreeBSD

OPTIONS_DEFINE=		DOCS NLS NOTIFY GLADE
OPTIONS_DEFAULT=	NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MGLADE}
LIB_DEPENDS+=	libgladeui-1.so:${PORTSDIR}/devel/glade3
CONFIGURE_ARGS+=--enable-gladeui
.else
CONFIGURE_ARGS+=--disable-gladeui
.endif

.include <bsd.port.mk>
