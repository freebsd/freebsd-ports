# New ports collection makefile for:	xforms
# Version required:	0.86
# Date created:		28 March 1997
# Whom:			gena
#
# $Id: Makefile,v 1.9 1997/02/23 12:07:29 jkh Exp $
#

DISTNAME=	bxform-086
PKGNAME=	xforms-0.86
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://einstein.phys.uwm.edu/pub/xforms/freeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

USE_X11=	yes
WRKSRC=		${WRKDIR}/xforms
MAN1=		fdesign.1
MAN5=		xforms.5

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
