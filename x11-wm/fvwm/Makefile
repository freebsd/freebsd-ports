# New ports collection makefile for:	fvwm
# Version required:	1.24r
# Date created:		12 May 1995
# Whom:			me
#
# $Id: Makefile,v 1.20 1996/05/27 12:33:48 peter Exp $
#

DISTNAME=	fvwm-1.24r
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/window-managers

MAINTAINER=	me@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=	Makefiles all

post-install:
	@mkdir -p ${PREFIX}/include/X11/pixmaps
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKSRC}/fvwm_icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
