# New ports collection makefile for:	gnome
# Date created:		17 Aug 1998
# Whom:			Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnome
PORTVERSION=	1.2
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12 \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		esd.2:${PORTSDIR}/audio/esound \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		ORBit.2:${PORTSDIR}/devel/ORBit \
		gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtop.1:${PORTSDIR}/devel/libgtop \
		xml.5:${PORTSDIR}/textproc/libxml \
		ghttp.1:${PORTSDIR}/www/libghttp \
		glade.3:${PORTSDIR}/devel/libglade \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		capplet.4:${PORTSDIR}/sysutils/gnomecontrolcenter \
		panel_applet.4:${PORTSDIR}/x11/gnomecore \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint

RUN_DEPENDS=	${X11BASE}/share/themes/Metal/ICON.png:${PORTSDIR}/x11-toolkits/gtk-engines \
		another_clock_applet:${PORTSDIR}/x11/gnomeapplets \
		gmc:${PORTSDIR}/x11-fm/gnomemc \
		bug-buddy:${PORTSDIR}/devel/bugbuddy \
		glade:${PORTSDIR}/devel/glade \
		${LOCALBASE}/lib/python1.5/site-packages/_appletmodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		${X11BASE}/share/gnome/help/users-guide/aboutug.html:${PORTSDIR}/misc/gnomeusersguide \
		gcalc:${PORTSDIR}/misc/gnomeutils \
		gnomecard:${PORTSDIR}/deskutils/gnomepim \
		${X11BASE}/share/gnome/sounds/startup.wav:${PORTSDIR}/audio/gnomeaudio \
		gtcd:${PORTSDIR}/audio/gnomemedia \
		gnomine:${PORTSDIR}/games/gnomegames \
		ElectricEyes:${PORTSDIR}/graphics/electriceyes \
		gnumeric:${PORTSDIR}/math/gnumeric \
		gtop:${PORTSDIR}/sysutils/gtop \
		ggv:${PORTSDIR}/print/ggv

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
