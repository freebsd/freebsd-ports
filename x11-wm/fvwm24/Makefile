# New ports collection makefile for:	fvwm2
# Version required:	2.0.43
# Date created:		20 Jan 1996
# Whom:			peter
#
# $Id: Makefile,v 1.3 1996/07/22 04:52:15 pst Exp $
#

DISTNAME=	fvwm-2.0.43
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	peter@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=	Makefiles all

post-install:
	@mkdir -p ${PREFIX}/include/X11/pixmaps
	${INSTALL} -c -m 444 ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
