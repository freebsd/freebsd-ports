# New ports collection makefile for:	gnome
# Version required:	0.30
# Date created:		17 Aug 1998
# Whom:			Yukihiro Nakai <Nakai@technologist.com>
#
# $Id$
#

DISTNAME=	gnome-0.30
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gnome.0:${PORTSDIR}/x11/gnomelibs \
		panel_applet.0:${PORTSDIR}/x11/gnomecore \
		gdkcardimage.0:${PORTSDIR}/games/gnomegames \
		gxsnmp.o:${PORTSDIR}/sysutils/gnomeadmin
RUN_DEPENDS=	gcalc:${PORTSDIR}/misc/gnomeutils \
		ElectricEyes:${PORTSDIR}/graphics/electriceyes \
		ggc:${PORTSDIR}/print/ggv \
		gnumeric:${PORTSDIR}/math/gnumeric

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install=	# empty

.include <bsd.port.mk>
