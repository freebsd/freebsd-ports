# New ports collection makefile for:	emu
# Date created:		13 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	emu
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	me@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	xrdb:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS+=	xrdb:${PORTSDIR}/x11/XFree86-4-clients
.endif

.if !defined(DISPLAY) || ${DISPLAY} == ""
BROKEN=		"Requires an active X session (and DISPLAY variable) to run xrdb.  Please compile this while running X."
.endif

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/emu
MAN1=		emu.1

pre-configure:
	cd ${WRKSRC}/client ; ${LN} -s ../doc/emu.man .

.include <bsd.port.post.mk>
