# New ports collection makefile for:	fvwm2
# Version required:	2.0.39
# Date created:		20 Jan 1996
# Whom:			peter
#
# $Id$
#

DISTNAME=	fvwm-2.0.40
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	peter@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=	Makefiles all
WRKSRC=		${WRKDIR}/fvwm

post-configure:
	cd ${WRKSRC}/modules/FvwmConfig; xmkmf

post-install:
	@mkdir -p ${PREFIX}/include/X11/pixmaps
	cp ${WRKSRC}/fvwm_icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
