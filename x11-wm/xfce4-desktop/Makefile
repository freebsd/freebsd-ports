# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-desktop
PORTVERSION=	4.10.2
PORTREVISION=	2
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/xfdesktop/${PORTVERSION:R}
DISTNAME=	xfdesktop-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's desktop manager

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libwnck-1.so:${PORTSDIR}/x11-toolkits/libwnck \
		libnotify.so:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv garcon libmenu libutil libexo xfconf
USES=	pathfix pkgconfig gmake
USE_XORG=	x11 sm

CONFIGURE_ARGS+=--enable-gio-unix \
	--enable-notifications

OPTIONS_DEFINE=		THUNAR NLS
OPTIONS_DEFAULT=	THUNAR NLS
THUNAR_DESC=	Enable thunar support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHUNAR}
CONFIGURE_ARGS+=--enable-thunarx --with-file-manager-fallback=Thunar
USE_XFCE+=	thunar
.else
CONFIGURE_ARGS+=--disable-thunarx --without-file-manager-fallback
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po ||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
