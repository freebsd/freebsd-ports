# New ports collection makefile for:	fvwm
# Version required:	1.23b
# Date created:		25 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.15 1995/04/01 12:50:52 jkh Exp $
#

DISTNAME=	fvwm
PKGNAME=	fvwm-1.23b
CATEGORIES+=	x11
MASTER_SITES=	ftp://spcot.sanders.com/pub/fvwm/
DISTFILES=	fvwm-core.tar.gz fvwm-modules.tar.gz \
		fvwm-icons.tar.gz

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf

pre-install:
	@cp ${FILESDIR}/configure2.h ${WRKSRC}/configure.h
	@(cd ${WRKSRC}; ${MAKE} Makefiles)

.include <bsd.port.mk>
