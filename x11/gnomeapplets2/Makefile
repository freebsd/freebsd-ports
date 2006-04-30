# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnomeapplets2/Makefile,v 1.111 2006/04/13 07:52:40 bland Exp $
#

PORTNAME=	gnomeapplets2
PORTVERSION=	2.14.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-applets/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-applets-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the Gnome 2 Desktop Environment

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-system-tools.pc:${PORTSDIR}/sysutils/gnomesystemtools
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop2 \
		xklavier.10:${PORTSDIR}/x11/libxklavier \
		gucharmap.4:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/system-tools-backends.pc:${PORTSDIR}/sysutils/gnomesystemtools

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel \
		gail gnomedocutils
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gstreamer=0.10
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		FREEBSD_SYS=${FREEBSD_SYS}

GCONF_SCHEMAS=	charpick.schemas drivemount.schemas geyes.schemas \
		gswitchit.schemas gtik.schemas gweather.schemas \
		mixer.schemas multiload.schemas \
		stickynotes.schemas

FREEBSD_SYS?=	/usr/src/sys

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/libnotify.pc) || \
	defined(WITH_LIBNOTIFY)
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
PLIST_SUB=	BATTERY="@comment "
.else
GCONF_SCHEMAS+=	battstat.schemas
PLIST_SUB=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GCONF_SCHEMAS+=	cpufreq-applet.schemas
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/libgweather/weather-met.c

.include <bsd.port.post.mk>
