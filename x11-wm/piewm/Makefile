# New ports collection makefile for:	piewm
# Version required:	?
# Date created:		24 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.6 1995/02/11 13:51:31 asami Exp $
#

DISTNAME=	piewm
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
MAINTAINER=	asami@FreeBSD.ORG
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
