# New ports collection makefile for:	fvwm
# Version required:	1.23b
# Date created:		25 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.8 1994/10/06 02:56:58 jkh Exp $
#

DISTNAME=	fvwm
NO_WRKSUBDIR=	yes
DISTFILES=	fvwm-core.tar.gz fvwm-modules.tar.gz \
		fvwm-icons.tar.gz
MASTER_SITES=	ftp://spcot.sanders.com/pub/fvwm/
USE_IMAKE=	yes
DEPENDS=	${PORTSDIR}/x11/xpm

pre-install:
	@cp ${FILESDIR}/configure2.h ${WRKSRC}/configure.h
	@(cd ${WRKSRC}; ${MAKE} Makefiles)

.include <bsd.port.mk>
