# New ports collection makefile for:	fvwm
# Version required:	1.23b
# Date created:		25 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.7 1994/09/14 16:35:25 jkh Exp $
#

DISTNAME=	fvwm-1.23b
NO_WRKSUBDIR=	yes
DISTFILES=	fvwm-1.23b-core.tar.gz fvwm-1.23b-modules.tar.gz \
		fvwm-1.23-icons.tar.gz
MASTER_SITES=	ftp://spcot.sanders.com/pub/fvwm/
USE_IMAKE=	yes
DEPENDS=	${PORTSDIR}/x11/xpm

pre-install:
	@cp ${FILESDIR}/configure2.h ${WRKSRC}/configure.h
	@(cd ${WRKSRC}; ${MAKE} Makefiles)

.include <bsd.port.mk>
