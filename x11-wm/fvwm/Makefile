# New ports collection makefile for:	fvwm
# Version required:	1.24r
# Date created:		12 May 1995
# Whom:			me
#
# $Id: Makefile,v 1.22 1997/10/28 21:59:55 gj Exp $
#

DISTNAME=	fvwm-1.24r
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-1/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/1.x/

MAINTAINER=	me@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

NO_LATEST_LINK=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=	Makefiles all

post-install:
	@mkdir -p ${PREFIX}/include/X11/pixmaps
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 444 \
	${WRKSRC}/fvwm_icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
