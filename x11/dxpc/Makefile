# New ports collection makefile for:	dxpc
# Version required:     3.7.0
# Date created:		2 May 1998
# Whom:			Bruce A. Mah <bmah@ca.sandia.gov>
#
# $Id: Makefile,v 1.1.1.1 1998/05/17 06:27:45 mph Exp $
#

DISTNAME=       dxpc-3.7.0
CATEGORIES=	x11
MASTER_SITES=   ${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	bmah@ca.sandia.gov

MAN1=		dxpc.1

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

post-install:
	strip ${PREFIX}/bin/dxpc

.include <bsd.port.mk>
