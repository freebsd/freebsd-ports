# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The "meta-port" for KDE

.if !defined(MINIMAL_KDE)
RUN_DEPENDS+=	kjumpingcube:${PORTSDIR}/games/kdegames3 \
		kdessh:${PORTSDIR}/misc/kdeutils3 \
		kword:${PORTSDIR}/editors/koffice-kde3 \
		kppp:${PORTSDIR}/net/kdenetwork3 \
		kview:${PORTSDIR}/graphics/kdegraphics3 \
		kmix:${PORTSDIR}/multimedia/kdemultimedia3 \
		korganizer:${PORTSDIR}/deskutils/kdepim3 \
		cervisia:${PORTSDIR}/devel/kdesdk3 \
		kdevelop:${PORTSDIR}/devel/kdevelop \
		atlantikdesigner:${PORTSDIR}/misc/kdeaddons3 \
		khangman:${PORTSDIR}/misc/kdeedu3 \
		kcron:${PORTSDIR}/sysutils/kdeadmin3 \
		quanta:${PORTSDIR}/www/quanta \
		kmoon:${PORTSDIR}/x11-clocks/kdetoys3 \
		kmatrix.kss:${PORTSDIR}/x11-wm/kdeartwork3
.endif

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
