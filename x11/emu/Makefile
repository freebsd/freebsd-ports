# New ports collection makefile for:	emu
# Version required:	1.31
# Date created:		13 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.10 1996/11/18 09:55:23 asami Exp $
#

DISTNAME=	emu-1.31
PKGNAME=	emu-1.3.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	me@FreeBSD.org

USE_IMAKE=	yes
# only needs to connect to X server to run xrdb
#IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/emu

pre-configure:
	cd ${WRKSRC}/client ; ln -s ../doc/emu.man .

.include <bsd.port.mk>
