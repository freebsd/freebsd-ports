# New ports collection makefile for:   kde
# Version required:    around November 1997
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $Id: Makefile,v 1.5 1998/02/21 15:15:58 se Exp $
#

DISTNAME=	kde-2.1b
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore\\.0\\.90:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase \
		kcalc:${PORTSDIR}/misc/kdeutils \
		kmahjongg:${PORTSDIR}/games/kdegames \
		kghostview:${PORTSDIR}/graphics/kdegraphics \
		kmedia:${PORTSDIR}/audio/kdemultimedia \
#		kmail:${PORTSDIR}/net/kdenetwork

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
