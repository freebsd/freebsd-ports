# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/x11/gnome-session/Makefile,v 1.6 2010/06/24 10:03:55 kwm Exp $
#

PORTNAME=	gnome-session
PORTVERSION=	2.30.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME \
		http://www.marcuscom.com/downloads/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SPLASHES}:local
DIST_SUBDIR=	gnome2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		notify.1:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		upower-glib.1:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
    		${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XORG=	ice sm xau xext xrandr
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--enable-splash
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-session.1 gnome-wm.1 gnome-session-properties.1 \
		gnome-session-save.1
GCONF_SCHEMAS=	gnome-session.schemas

SPLASHES=	freebsd-splashes-gnome-2.18_1.tar

post-extract:
	cd ${WRKDIR} && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${SPLASHES}

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/gnome-splash.png \
		${PREFIX}/share/pixmaps/splash/original-gnome-splash.png
#	${INSTALL_DATA} ${WRKDIR}/freebsd-splashes-gnome-2.12/domix-splash-2.12.png \
#		${PREFIX}/share/pixmaps/splash/gnome-splash.png
.for splash in MaMBaNgGaoX-2.12.png adamw-piggy-2.12.png adamw-trophy-2.12.png andreas-slogan-2.12.png andreas-splash-2.12.png domix-splash-2.12.png domix-splash2-2.12.png mumija-2.12.png mumija2-2.12.png mumija3-2.12.png tremulant-2.12.png tremulant-blood-2.12.png tremulant-brushed-metal-2.12.png franz-splash_218.png adamw-bat-2.18.jpg adamw-conky-2.18.png adamw-cow-2.18.png adamw-mouth-2.18.png adamw-swing-2.18.png
	${INSTALL_DATA} ${WRKDIR}/freebsd-splashes-gnome-2.18/${splash} \
		${PREFIX}/share/pixmaps/splash
.endfor

.include <bsd.port.mk>
