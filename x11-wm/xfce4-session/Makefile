# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-session
PORTVERSION=	4.10.1
PORTREVISION=	1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager

BUILD_DEPENDS=	iceauth:${PORTSDIR}/x11/iceauth
RUN_DEPENDS=	iceauth:${PORTSDIR}/x11/iceauth \
		console-kit-daemon:${PORTSDIR}/sysutils/consolekit
LIB_DEPENDS=	wnck-1:${PORTSDIR}/x11-toolkits/libwnck \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		upower-glib:${PORTSDIR}/sysutils/upower \
		polkit.2:${PORTSDIR}/sysutils/policykit
# explicitly add SHLIB version number for policykit to prevent LIB_DEPENDS
# matching sysutils/polkit instead (which has libpolkit-agent.so.1)

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack
USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libmenu libutil xfconf
USE_XORG=	x11 sm ice

CONFIGURE_ARGS+=--enable-legacy-sm \
		--disable-systemd \
		--with-xsession-prefix=${PREFIX}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	NLS

MAN1=		xfce4-session.1 xfce4-session-logout.1

PLIST_SUB=	VERSION="4.6"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
