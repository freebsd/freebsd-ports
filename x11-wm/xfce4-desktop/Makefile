# New ports collection makefile for:	xfdesktop
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-desktop
PORTVERSION=	4.8.2
PORTREVISION=	4
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/xfdesktop/${PORTVERSION:R}
DISTNAME=	xfdesktop-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	XFce 4 desktop background manager and root menu

DOCSDIR=	${PREFIX}/share/doc/xfdesktop

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck \
		notify.4:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gtk20 intltool intlhack pkgconfig \
		desktopfileutils
USE_XFCE=	configenv garcon libmenu libutil xfconf

CONFIGURE_ARGS+=	--enable-gio-unix \
		--enable-notifications

OPTIONS=	THUNAR	"Enable thunar support"		on \
		NLS "Enable Native Language Support" on

MAN1=		xfdesktop.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_THUNAR)
CONFIGURE_ARGS+=--enable-thunarx --enable-exo
USE_XFCE+=	libexo thunar
.else
CONFIGURE_ARGS+=--disable-thunarx --disable-exo
.endif

.if !defined(WITHOUT_NLS)
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
