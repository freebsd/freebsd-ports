# New ports collection makefile for:	xforms
# Version required:	0.75
# Date created:		01 October 1995
# Whom:			gena
#
# $Id: Makefile,v 1.1.1.1 1995/10/03 01:17:55 jkh Exp $
#

DISTNAME=	bxform-075
PKGNAME=	xforms-0.75
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://bloch.phys.uwm.edu/pub/xforms/freeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
WRKSRC=		${WRKDIR}/xforms

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
