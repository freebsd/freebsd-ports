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

RUN_DEPENDS=	${X11BASE}/share/themes/Metal/ICON.png:${PORTSDIR}/x11-toolkits/gtk-engines \
		another_clock_applet:${PORTSDIR}/x11/gnomeapplets \
		gmc:${PORTSDIR}/x11-fm/gnomemc \
		bug-buddy:${PORTSDIR}/devel/bugbuddy \
		glade:${PORTSDIR}/devel/glade \
		${PYTHON_LIBDIR}/site-packages/_appletmodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		${X11BASE}/share/gnome/help/users-guide/C/aboutug.html:${PORTSDIR}/misc/gnomeusersguide \
		gcalc:${PORTSDIR}/misc/gnomeutils \
		gnomecard:${PORTSDIR}/deskutils/gnomepim \
		gtcd:${PORTSDIR}/audio/gnomemedia \
		gnomine:${PORTSDIR}/games/gnomegames \
		ElectricEyes:${PORTSDIR}/graphics/electriceyes \
		gnumeric:${PORTSDIR}/math/gnumeric \
		gtop:${PORTSDIR}/sysutils/gtop \
		ggv:${PORTSDIR}/print/ggv

NO_BUILD=	yes

USE_GNOME=	yes
USE_PYTHON=	yes

do-install:	# empty

.include <bsd.port.mk>
