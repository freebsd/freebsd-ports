# New ports collection makefile for:	KDE2
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	2.1.1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	will@FreeBSD.org

RUN_DEPENDS=	kjumpingcube:${PORTSDIR}/games/kdegames2 \
		kdessh:${PORTSDIR}/misc/kdeutils2 \
		kword:${PORTSDIR}/editors/koffice \
		kppp:${PORTSDIR}/net/kdenetwork2 \
		kview:${PORTSDIR}/graphics/kdegraphics2 \
		kmidi:${PORTSDIR}/audio/kdemultimedia2

USE_KDEBASE_VER=2
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
