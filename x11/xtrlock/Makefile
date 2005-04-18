# New ports collection makefile for:	xtrlock
# Date created:		18 May 2004
# Whom:			Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$
#

PORTNAME=	xtrlock
PORTVERSION=	2.0.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/x/xtrlock/
DISTNAME=	${PORTNAME}_2.0-${PORTVERSION:E}

MAINTAINER=	karma@ez.pereslavl.ru
COMMENT=	X Transparent Lock

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-2.0
MAKEFILE=	${FILESDIR}/Makefile

MAN1=		xtrlock.1
PLIST_FILES=	bin/xtrlock

.include <bsd.port.mk>
