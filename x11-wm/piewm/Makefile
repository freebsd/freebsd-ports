# New ports collection makefile for:	piewm
# Version required:	?
# Date created:		24 November 1994
# Whom:			asami
#
# $id:$
#

DISTNAME=	piewm
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z
PKG_CMD=	pkg_create -N
DEPENDS=        ${PORTSDIR}/x11/xpm

# piewm.tar.Z includes and old version of xpm, and also a bunch of .o
#  files plus an executable

pre-configure:
	@/bin/rm -rf ${WRKDIR}/xpm

pre-build:
	@(cd ${WRKSRC}; ${MAKE} clean)

.include <bsd.port.mk>
