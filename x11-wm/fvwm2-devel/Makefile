# New ports collection makefile for:	fvwm2
# Version required:	2.0.39
# Date created:		20 Jan 1996
# Whom:			peter
#
# $Id: Makefile,v 1.1.1.1 1996/03/09 14:42:56 asami Exp $
#

DISTNAME=	fvwm-2.0.41
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	peter@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=	Makefiles all

post-configure:
	cd ${WRKSRC}/modules/FvwmConfig; xmkmf

post-install:
	@mkdir -p ${PREFIX}/include/X11/pixmaps
	${INSTALL} -c -m 444 ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
