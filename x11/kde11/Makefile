# New ports collection makefile for:   kde
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	1.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase11 \
		kcalc:${PORTSDIR}/misc/kdeutils11 \
		kmahjongg:${PORTSDIR}/games/kdegames11 \
		kghostview:${PORTSDIR}/graphics/kdegraphics11 \
		kmail:${PORTSDIR}/net/kdenetwork11 \
		kmedia:${PORTSDIR}/audio/kdemultimedia11

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
