# New ports collection makefile for:	emu
# Version required:	1.31
# Date created:		13 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

DISTNAME=	emu-1.31
PKGNAME=	emu-1.3.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	me@FreeBSD.org

.if !defined(DISPLAY) || ${DISPLAY} == ""
BROKEN=         "Requires an active X session (and DISPLAY variable) to run xrdb.  Please compile this while running X."
.endif

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/emu
MAN1=		emu.1

pre-configure:
	cd ${WRKSRC}/client ; ${LN} -s ../doc/emu.man .

.include <bsd.port.mk>
