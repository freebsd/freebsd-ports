# New ports collection makefile for:	xforms
# Version required:	0.81
# Date created:		29 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.4 1996/05/08 06:11:12 jkh Exp $
#

DISTNAME=	bxform-081
PKGNAME=	xforms-0.81
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://laue.phys.uwm.edu/pub/xforms/freeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

USE_X11=	yes
WRKSRC=		${WRKDIR}/xforms

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
