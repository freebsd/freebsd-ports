# New ports collection makefile for:   kde
# Version required:    around November 1997
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $Id: Makefile,v 1.17 1999/01/07 00:51:58 se Exp $
#

DISTNAME=	kde-1.1a1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase11 \
		kcalc:${PORTSDIR}/misc/kdeutils11 \
		kmahjongg:${PORTSDIR}/games/kdegames11 \
		kghostview:${PORTSDIR}/graphics/kdegraphics11 \
		kmail:${PORTSDIR}/net/kdenetwork11 \
		kmedia:${PORTSDIR}/audio/kdemultimedia11

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
