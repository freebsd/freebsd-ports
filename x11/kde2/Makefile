# New ports collection makefile for:   kde
# Version required:    around November 1997
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $Id$
#

DISTNAME=	kde-1.2b
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	mimelib\\.1\\.0:${PORTSDIR}/converters/kdesupport \
		kdecore\\.0\\.11:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kmail:${PORTSDIR}/net/kdenetwork \
		kcalc:${PORTSDIR}/misc/kdeutils \
		kmahjongg:${PORTSDIR}/games/kdegames \
		kwm:${PORTSDIR}/x11/kdebase

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
