# New ports collection makefile for:	KDE3
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	3.0.5
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS+=	kjumpingcube:${PORTSDIR}/games/kdegames3 \
		kdessh:${PORTSDIR}/misc/kdeutils3 \
		kword:${PORTSDIR}/editors/koffice-kde3 \
		kppp:${PORTSDIR}/net/kdenetwork3 \
		kview:${PORTSDIR}/graphics/kdegraphics3 \
		kmidi:${PORTSDIR}/multimedia/kdemultimedia3

.if make(package)
DEPENDS_TARGET="package"
.endif # .if make(package)

USE_QT_VER=3
USE_KDELIBS_VER=3
USE_KDEBASE_VER=3

NO_BUILD=	yes

do-install:	# empty
	${DO_NADA}

.include <bsd.port.mk>
