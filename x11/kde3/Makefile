# New ports collection makefile for:   kde
# Version required:    around November 1997
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $Id: Makefile,v 1.15 1998/10/01 19:49:10 brian Exp $
#

DISTNAME=	kde-1.1a1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase \
		kcalc:${PORTSDIR}/misc/kdeutils \
		kmahjongg:${PORTSDIR}/games/kdegames \
		kghostview:${PORTSDIR}/graphics/kdegraphics \
		kmail:${PORTSDIR}/net/kdenetwork \
		kmedia:${PORTSDIR}/audio/kdemultimedia

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
