# New ports collection makefile for:	emu
# Version required:	1.31
# Date created:		13 September 1994
# Whom:			jkh
#
# $Id$
#

DISTNAME=	emu-1.31
PKGNAME=	emu-1.3.1
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
CATEGORIES+=	x11

MAINTAINER=	me@FreeBSD.org

USE_IMAKE=	yes
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/emu

pre-configure:
	cd ${WRKSRC}/client ; ln -s ../doc/emu.man .

.include <bsd.port.mk>
