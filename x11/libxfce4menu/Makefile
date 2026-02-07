PORTNAME=	libxfce4menu
PORTVERSION=	4.20.2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DISTNAME=	libxfce4ui-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Widgets library for the Xfce desktop environment
WWW=		https://gitlab.xfce.org/xfce/libxfce4ui

LICENSE=	GPLv2

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libgtop-2.0.so:devel/libgtop \
		libgudev-1.0.so:devel/libgudev \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbufextra:run glib20 gtk30
USE_LDCONFIG=	yes
USE_XFCE=	libutil xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-epoxy \
		--enable-glibtop \
		--enable-libsm \
		--enable-x11 \
		--with-vendor-info=${OPSYS} \
		--without-html-dir
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		GIR GLADE NLS STARTUP VAPI WAYLAND
OPTIONS_DEFAULT=	GIR STARTUP VAPI WAYLAND
OPTIONS_SUB=		yes

GIR_DESC=	Use Gobject Introspection
STARTUP_DESC=	Startup notification

GIR_USE=		GNOME=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

GLADE_LIB_DEPENDS=	libgladeui-2.so:devel/glade
GLADE_USE=		GNOME=libxml2
GLADE_CONFIGURE_ENABLE=	gladeui2

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

STARTUP_LIB_DEPENDS=		libstartup-notification-1.so:x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification

VAPI_IMPLIES=		GIR
VAPI_USES=		vala:build
VAPI_CONFIGURE_ENABLE=	vala

WAYLAND_CONFIGURE_ENABLE=	wayland

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|' ${WRKSRC}/xfce4-about/main.c

.include <bsd.port.mk>
