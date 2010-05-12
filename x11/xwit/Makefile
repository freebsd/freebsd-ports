# New ports collection makefile for:	xwit
# Date created:				15 June 1998
# Whom:					Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xwit
PORTVERSION=	3.4
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/utilities:source1 CRITICAL:source2
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:source1 \
		${PORTNAME}-patchset-${PORTVERSION}${EXTRACT_SUFX}:source2

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	X interface tool

USE_IMAKE=	yes
USE_XORG=	x11 xext

MAN1=		xwit.1
PLIST_FILES=	bin/xwit

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}-patchset-${PORTVERSION}/patch-*

.include <bsd.port.mk>
