# New ports collection makefile for:	gnome
# Version required:	0.99.3
# Date created:		17 Aug 1998
# Whom:			Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.2 1998/10/30 06:32:40 asami Exp $
#

DISTNAME=	gnome-0.99.3
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs \
		panel_applet.1:${PORTSDIR}/x11/gnomecore \
		gdkcardimage.1:${PORTSDIR}/games/gnomegames \
		gnomeprint.0:${PORTSDIR}/print/gnomeprint
#		gxsnmp.1:${PORTSDIR}/sysutils/gnomeadmin
RUN_DEPENDS=	gcalc:${PORTSDIR}/misc/gnomeutils \
		ElectricEyes:${PORTSDIR}/graphics/electriceyes \
#		ggv:${PORTSDIR}/print/ggv \
		gtop:${PORTSDIR}/sysutils/gtop \
		gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter \
		gnomecard:${PORTSDIR}/deskutils/gnomepim \
		gnumeric:${PORTSDIR}/math/gnumeric

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
