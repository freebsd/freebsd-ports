# New ports collection makefile for:   kde
# Version required:    around November 1997
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $Id: Makefile,v 1.11 1998/05/21 21:35:19 se Exp $
#

DISTNAME=	kde-4.1b
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore\\.0\\.91:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase \
		kcalc:${PORTSDIR}/misc/kdeutils \
		kmahjongg:${PORTSDIR}/games/kdegames \
		kghostview:${PORTSDIR}/graphics/kdegraphics \
		kmail:${PORTSDIR}/net/kdenetwork \
#		kmedia:${PORTSDIR}/audio/kdemultimedia

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
