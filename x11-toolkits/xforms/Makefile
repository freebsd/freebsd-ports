# New ports collection makefile for:	xforms
# Version required:	0.75
# Date created:		01 October 1995
# Whom:			gena
#
# $Id: $
#

DISTNAME=	bxform-075
PKGNAME=	xforms-0.75
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/xforms
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://bloch.phys.uwm.edu/pub/xforms/freeBSD/

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

PREFIX=		/usr/X11R6

MAINTAINER=	gena@NetVision.net.il

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
