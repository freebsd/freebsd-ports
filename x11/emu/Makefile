# New ports collection makefile for:	emu
# Version required:	1.31
# Date created:		13 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.11 1997/03/06 04:50:09 asami Exp $
#

DISTNAME=	emu-1.31
PKGNAME=	emu-1.3.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	me@FreeBSD.org

.if !defined(DISPLAY) 
BROKEN=         Requires an X Display to build
.endif
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/emu

pre-configure:
	cd ${WRKSRC}/client ; ln -s ../doc/emu.man .

.include <bsd.port.mk>
