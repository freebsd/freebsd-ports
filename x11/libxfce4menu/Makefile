# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxfce4menu
PORTVERSION=	4.14.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DISTNAME=	libxfce4ui-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Widgets library for the Xfce desktop environment

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool
USE_LDCONFIG=	yes
USE_XFCE=	xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-vendor-info=${OPSYS} --without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR GLADE GTK2 NLS STARTUP VAPI
OPTIONS_DEFAULT=	GIR GTK2 STARTUP VAPI
OPTIONS_SUB=		yes

GIR_DESC=		Use Gobject Introspection

GIR_USE=		gnome=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

GLADE_CONFIGURE_ENABLE=	gladeui2
GLADE_LIB_DEPENDS=	libgladeui-2.so:devel/glade
GLADE_USE=		gnome=libxml2

GTK2_CONFIGURE_ENABLE=	gtk2
GTK2_USE=		gnome=gtk20

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

STARTUP_CONFIGURE_ENABLE=	startup-notification
STARTUP_DESC=		Startup notification
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

VAPI_BUILD_DEPENDS=	vapigen:lang/vala
VAPI_CONFIGURE_ENABLE=	vala
VAPI_IMPLIES=		GIR

.include <bsd.port.mk>
