# New ports collection makefile for:	KDE2
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	1.90
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2
RUN_DEPENDS=	konqueror:${PORTSDIR}/x11/kdebase2 \
		kcalc:${PORTSDIR}/misc/kdeutils2 \
		kmahjongg:${PORTSDIR}/games/kdegames2 \
		kmail:${PORTSDIR}/net/kdenetwork2

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
