# New ports collection makefile for:	gnome
# Date created:		17 Aug 1998
# Whom:			Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnome
PORTVERSION=	1.0.53
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12 \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		ORBit.2:${PORTSDIR}/devel/ORBit \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		esd.2:${PORTSDIR}/audio/esound \
		gnome.3:${PORTSDIR}/x11/gnomelibs \
		gtop.1:${PORTSDIR}/devel/libgtop \
		xml.5:${PORTSDIR}/textproc/libxml \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint \
		ghttp.1:${PORTSDIR}/www/libghttp \
		obgnome.1:${PORTSDIR}/lang/gnomeobjc \
		glade.3:${PORTSDIR}/devel/libglade
RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/startup.wav:${PORTSDIR}/audio/gnomeaudio \
		panel:${PORTSDIR}/x11/gnomecore \
		gtcd:${PORTSDIR}/audio/gnomemedia \
		gnomecard:${PORTSDIR}/deskutils/gnomepim \
		gnomine:${PORTSDIR}/games/gnomegames \
		ElectricEyes:${PORTSDIR}/graphics/electriceyes \
		gcalc:${PORTSDIR}/misc/gnomeutils \
		gtalk:${PORTSDIR}/net/gnomenetwork \
		ggv:${PORTSDIR}/print/ggv \
		gulp:${PORTSDIR}/sysutils/gnomeadmin \
		gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter \
		gtop:${PORTSDIR}/sysutils/gtop \
		gmc:${PORTSDIR}/x11-fm/gnomemc \
		gnumeric:${PORTSDIR}/math/gnumeric

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
