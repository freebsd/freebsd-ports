# New ports collection makefile for:	fvwm
# Version required:	1.23b
# Date created:		25 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1994/11/17 00:08:59 jkh Exp $
#

DISTNAME=	fvwm
NO_WRKSUBDIR=	yes
DISTFILES=	fvwm-core.tar.gz fvwm-modules.tar.gz \
		fvwm-icons.tar.gz
MASTER_SITES=	ftp://spcot.sanders.com/pub/fvwm/
USE_IMAKE=	yes
DEPENDS=	${PORTSDIR}/x11/xpm
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-r ${PKGDIR}/REQUIRES -p ${PREFIX}

pre-install:
	@cp ${FILESDIR}/configure2.h ${WRKSRC}/configure.h
	@(cd ${WRKSRC}; ${MAKE} Makefiles)



.include <bsd.port.mk>
