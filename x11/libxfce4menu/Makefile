# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxfce4menu
PORTVERSION=	4.12.1
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/xfce/libxfce4ui/${PORTVERSION:R}
DISTNAME=	libxfce4ui-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Widgets library for the Xfce desktop environment

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USES=		gettext-tools gmake gnome libtool pathfix pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo glib20 gtk20 intlhack intltool
USE_LDCONFIG=	yes
USE_XFCE=	xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-vendor-info=${OPSYS} --without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limit:^4\.12\.

OPTIONS_DEFINE=		GLADE GTK3 NLS STARTUP
OPTIONS_DEFAULT=	GTK3 STARTUP
OPTIONS_SUB=		yes

GLADE_CONFIGURE_ENABLE=	gladeui
GLADE_LIB_DEPENDS=	libgladeui-1.so:devel/glade3

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=		gnome=gtk30

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

STARTUP_CONFIGURE_ENABLE=	startup-notification
STARTUP_DESC=		Startup notification
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

.include <bsd.port.mk>
