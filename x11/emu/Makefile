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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal emulator for the X Window System

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/emu

.if !defined(DISPLAY) || ${DISPLAY} == ""
IGNORE=		Requires an active X session (and DISPLAY variable) to run xrdb.  Please compile this while running X.
.endif

MAN1=		emu.1

pre-configure:
	cd ${WRKSRC}/client ; ${LN} -s ../doc/emu.man .

.include <bsd.port.mk>
