# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	workrave
PORTVERSION=	1.9.4
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RSI prevention tool

BUILD_DEPENDS=	gdome-config:${PORTSDIR}/textproc/gdome2

OPTIONS_DEFINE=	GNOME NETWORK NLS
NETWORK_DESC=	Build with network support

INSTALLS_ICONS=	yes
DESKTOP_ENTRIES="Workrave" "RSI prevention tool" \
		"${DATADIR}/images/workrave-icon-small.png" \
		"workrave" \
		"Utility;" \
		false

USE_XORG=	x11 xmu recordproto xtst xext
USES=		pathfix pkgconfig  gmake
USE_GNOME=	gnomeprefix intlhack gconf2 intltool
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib `pkg-config --libs libgnomeui-2.0`
CONFIGURE_ARGS=	--enable-gconf --disable-pulse

.include <bsd.port.options.mk>
LIB_DEPENDS+=	libgdome.so:${PORTSDIR}/textproc/gdome2

.if ${PORT_OPTIONS:MGNOME}
LIB_DEPENDS+=	libgnomeuimm-2.6.so:${PORTSDIR}/x11-toolkits/libgnomeuimm26
USE_GNOME+=	gnomepanel
PLIST_SUB+=	GNOME=""
.else
LIB_DEPENDS+=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

.if ${PORT_OPTIONS:MNETWORK}
LIB_DEPENDS+=	libgnet-2.0.so:${PORTSDIR}/net/gnet2
.else
CONFIGURE_ARGS+=--disable-distribution
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
