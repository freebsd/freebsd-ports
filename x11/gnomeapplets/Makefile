# New ports collection makefile for:	gnomeapplets
# Date created:				26th May 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeapplets
PORTVERSION=	1.4.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-applets/1.4
DISTNAME=	gnome-applets-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libpanel gnomevfs gnomecanvas libghttp
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		another_clock_applet.1 asclock_applet.1 \
		cdplayer_applet.1 charpick_applet.1 clockmail_applet.1 \
		cpumemusage_applet.1 diskusage_applet.1 drivemount_applet.1 \
		esdpvd.1 fifteen_applet.1 geyes_applet.1 gkb_applet.1 \
		gnotes_applet.1 gtik2_applet.1 gweather_applet.1 jbc_applet.1 \
		life_applet.1 mini-commander_applet.1 mixer_applet.1 \
		modemlights_applet.1 multiload_applet.1 odometer_applet.1 \
		quicklaunch_applet.1 slash_applet.1 sound-monitor_applet.1 \
		tickastat_applet.1 webcontrol_applet.1 whereami_applet.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.in
PLIST_SUB=	BATTERY="@comment "
.else
PLIST_SUB=	BATTERY=""
MAN1+=	battery_applet.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
