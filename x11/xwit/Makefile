# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xwit
PORTVERSION=	3.4
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/utilities:source1 CRITICAL:source2
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:source1 \
		${PORTNAME}-patchset-${PORTVERSION}${EXTRACT_SUFX}:source2

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	X interface tool

USES=		imake
USE_XORG=	x11 xext
MAKE_JOBS_SAFE=	yes

MAN1=		xwit.1
PLIST_FILES=	bin/xwit

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}-patchset-${PORTVERSION}/patch-*

.include <bsd.port.mk>
