# New ports collection makefile for:	fvwm
# Version required:	1.23b
# Date created:		25 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.14 1995/03/27 13:24:18 asami Exp $
#

DISTNAME=	fvwm
NO_WRKSUBDIR=	yes
DISTFILES=	fvwm-core.tar.gz fvwm-modules.tar.gz \
		fvwm-icons.tar.gz
MASTER_SITES=	ftp://spcot.sanders.com/pub/fvwm/
CATEGORIES+=	x11
USE_IMAKE=	yes
XMKMF=		xmkmf
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

pre-install:
	@cp ${FILESDIR}/configure2.h ${WRKSRC}/configure.h
	@(cd ${WRKSRC}; ${MAKE} Makefiles)



.include <bsd.port.mk>
