# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$
#

PORTNAME=	xfce4-desktop
PORTVERSION=	4.10.0
PORTREVISION=	4
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfdesktop-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's desktop manager

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		wnck-1:${PORTSDIR}/x11-toolkits/libwnck \
		notify:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gtk20 intltool intlhack desktopfileutils
USE_XFCE=	configenv garcon libmenu libutil libexo xfconf
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=--enable-gio-unix \
	--enable-notifications

OPTIONS_DEFINE=		THUNAR NLS
OPTIONS_DEFAULT=	THUNAR NLS
THUNAR_DESC=	Enable thunar support

MAN1=		xfdesktop.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHUNAR}
CONFIGURE_ARGS+=--enable-thunarx --with-file-manager-fallback=Thunar
USE_XFCE+=	thunar
.else
CONFIGURE_ARGS+=--disable-thunarx --without-file-manager-fallback
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
