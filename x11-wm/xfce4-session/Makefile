# New ports collection makefile for:	xfce4-session
# Date created:		2003-10-30
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-session
PORTVERSION=	4.8.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Session manager for the Xfce 4 desktop environment

BUILD_DEPENDS=	iceauth:${PORTSDIR}/x11/iceauth
RUN_DEPENDS=	iceauth:${PORTSDIR}/x11/iceauth \
		console-kit-daemon:${PORTSDIR}/sysutils/consolekit
LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		upower-glib.1:${PORTSDIR}/sysutils/upower \
		polkit.2:${PORTSDIR}/sysutils/policykit

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libmenu libutil panel xfconf
USE_XORG=	x11 sm ice

CONFIGURE_ARGS+=	--enable-panel-plugin \
		--enable-session-screenshots \
		--enable-legacy-sm \
		--disable-gnome \
		--disable-libgnome-keyring

OPTIONS=	NLS	"Enable Native Language Support"	on  \
		HAL	"Enable HAL Support"			off

.include <bsd.port.options.mk>

MAN1=		xfce4-session.1 xfce4-session-logout.1

PLIST_SUB=	VERSION="4.6"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif
.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=--disable-hal
.endif

post-install:
	@${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
