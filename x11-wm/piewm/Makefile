# New ports collection makefile for:	piewm
# Version required:	?
# Date created:		24 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.5 1995/01/13 12:49:18 jkh Exp $
#

DISTNAME=	piewm
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z
PKG_CMD=	pkg_create -N
LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

# piewm.tar.Z includes and old version of xpm, and also a bunch of .o
#  files plus an executable

pre-configure:
	@/bin/rm -rf ${WRKDIR}/xpm

pre-build:
	@(cd ${WRKSRC}; ${MAKE} clean)

.include <bsd.port.mk>
