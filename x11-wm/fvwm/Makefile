# New ports collection makefile for:	fvwm
# Version required:	1.24r
# Date created:		12 May 1995
# Whom:			me
#
# $Id: Makefile,v 1.17 1995/05/13 03:13:07 asami Exp $
#

DISTNAME=	fvwm-1.24r
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/X11/window-managers/
CATEGORIES+=	x11

MAINTAINER=	me@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf

post-install:
	@mkdir -p ${PREFIX}/include/X11/pixmaps
	cp ${WRKSRC}/fvwm_icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
