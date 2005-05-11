# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeapplets2
PORTVERSION=	2.10.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-applets/2.10
DISTNAME=	gnome-applets-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the Gnome 2 Desktop Environment

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-system-tools.pc:${PORTSDIR}/sysutils/gnomesystemtools
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2 \
		xklavier.10:${PORTSDIR}/x11/libxklavier \
		gucharmap.4:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/system-tools-backends.pc:${PORTSDIR}/sysutils/gnomesystemtools

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel \
		gail
USE_GSTREAMER=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		FREEBSD_SYS=${FREEBSD_SYS}

GCONF_SCHEMAS=	charpick.schemas drivemount.schemas geyes.schemas \
		gswitchit.schemas gtik.schemas gweather.schemas \
		mini-commander-global.schemas mini-commander.schemas \
		mixer.schemas multiload.schemas \
		stickynotes.schemas

FREEBSD_SYS?=	/usr/src/sys

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
PLIST_SUB=	BATTERY="@comment "
.else
GCONF_SCHEMAS+=	battstat.schemas
PLIST_SUB=	BATTERY=""

.if ${OSVERSION} < 600019
.if ${OSVERSION} < 503105 || ${OSVERSION} >= 600000
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "              W  A  R  N  I  N  G"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} "* gnomeapplets2 requires that you have your kernel  *"
	@${ECHO_MSG} "* sources installed. If your kernel sources         *"
	@${ECHO_MSG} "* are somewhere other than /usr/src/sys, you        *"
	@${ECHO_MSG} "* may set the FREEBSD_SYS variable to the           *"
	@${ECHO_MSG} "* correct path.                                     *"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} ""
.endif
.endif
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GCONF_SCHEMAS+=	cpufreq-applet.schemas
.endif

.include <bsd.port.post.mk>
