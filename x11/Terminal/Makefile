# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	Terminal
PORTVERSION=	0.4.8
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME:L}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack vte desktopfileutils
USE_XFCE=	configenv libexo
USE_XORG=	x11
USE_PKGCONFIG=	build

CONFIGURE_ARGS=	--without-gnome-default-appsdir

OPTIONS_DEFINE=	DBUS NLS

MAN1=		Terminal.1
MANLANG=	"" ca da el es fr gl id it ja pt ru sv ug zh_CN

.include  <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-doc-Makefile.in
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
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

.include <bsd.port.post.mk>
