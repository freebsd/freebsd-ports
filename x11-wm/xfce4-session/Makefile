# New ports collection makefile for:	xfce4-session
# Date created:		2003-10-30
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-session
PORTVERSION=	4.10.0
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager

#CONFLICTS=	xfce4-utils-4.8.*

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
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack pkgconfig desktopfileutils
USE_LDCONFIG=	yes
USE_XFCE=	configenv libmenu libutil panel xfconf
USE_XORG=	x11 sm ice

CONFIGURE_ARGS+=--enable-legacy-sm \
	--disable-libgnome-keyring \
	--with-xsession-prefix=${LOCALBASE}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	NLS	"Enable Native Language Support"	on \
	GNUPG "Add support of GNU Privacy Guard" off

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

.if defined(WITH_GNUPG)
RUN_DEPENDS+=	gpg-agent:${PORTSDIR}/security/gnupg
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
	@-update-desktop-database

.include <bsd.port.mk>
