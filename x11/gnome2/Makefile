# New ports collection makefile for:	gnome
# Version required:	1.0.0
# Date created:		17 Aug 1998
# Whom:			Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.4 1999/01/21 06:10:09 jkh Exp $
#

DISTNAME=	gnome-1.0.0
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	gtcd:${PORTSDIR}/audio/gnomemedia \
		gnomecard:${PORTSDIR}/deskutils/gnomepim \
		gnomine:${PORTSDIR}/games/gnomegames \
		ElectricEyes:${PORTSDIR}/graphics/electriceyes \
		gnumeric:${PORTSDIR}/math/gnumeric \
		gcalc:${PORTSDIR}/misc/gnomeutils \
		gtalk:${PORTSDIR}/net/gnomenetwork \
		gulp:${PORTSDIR}/sysutils/gnomeadmin \
		gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter \
		gtop:${PORTSDIR}/sysutils/gtop \
		gmc:${PORTSDIR}/x11-fm/gnomemc

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
