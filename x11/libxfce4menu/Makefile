PORTNAME=	libxfce4menu
PORTVERSION=	4.18.4
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DISTNAME=	libxfce4ui-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Widgets library for the Xfce desktop environment
WWW=		https://www.xfce.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libgtop-2.0.so:devel/libgtop \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_LDCONFIG=	yes
USE_XFCE=	libutil xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-vendor-info=${OPSYS} --without-html-dir \
		--enable-glibtop --enable-epoxy \
		--disable-gudev
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR GLADE NLS STARTUP VAPI
OPTIONS_DEFAULT=	GIR STARTUP VAPI
OPTIONS_SUB=		yes

GIR_DESC=		Use Gobject Introspection

GIR_USE=		gnome=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

GLADE_CONFIGURE_ENABLE=	gladeui2
GLADE_LIB_DEPENDS=	libgladeui-2.so:devel/glade
GLADE_USE=		gnome=libxml2

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

STARTUP_CONFIGURE_ENABLE=	startup-notification
STARTUP_DESC=		Startup notification
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

VAPI_USES=		vala:build
VAPI_CONFIGURE_ENABLE=	vala
VAPI_IMPLIES=		GIR

.include <bsd.port.mk>
