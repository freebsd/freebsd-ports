# New ports collection makefile for:   kde
# Version required:    around November 1997
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $Id: Makefile,v 1.13 1998/07/13 23:35:36 se Exp $
#

DISTNAME=	kde-1.0
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore\\.1\\.0:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase \
		kcalc:${PORTSDIR}/misc/kdeutils \
		kmahjongg:${PORTSDIR}/games/kdegames \
		kghostview:${PORTSDIR}/graphics/kdegraphics \
		kmail:${PORTSDIR}/net/kdenetwork \
		kmedia:${PORTSDIR}/audio/kdemultimedia

BROKEN_ELF=	depends on kdelibs

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
