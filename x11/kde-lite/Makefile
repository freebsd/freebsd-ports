# -*-mode: makefile-*-
# New ports collection makefile for:	KDE release ports
# Date created:				Sun Nov 30 19:55 EST 2003
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=		-lite

MAINTAINER=		re@FreeBSD.org
COMMENT=		The FreeBSD release "meta-port" for KDE

MASTERDIR=		${.CURDIR}/../../x11/kde3
.if defined(IS_INTERACTIVE)
CONFLICTS=		kde-[0-9]*
.endif

WITHOUT_KOFFICE=	yes
WITHOUT_KDESDK=		yes
WITHOUT_KDEVELOP=	yes
WITHOUT_KDEEDU=		yes
WITHOUT_KDEPIM=		yes
WITHOUT_QUANTA=		yes

.include "${MASTERDIR}/Makefile"
