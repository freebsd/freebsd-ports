# New ports collection Makefile for: rxvt
# Version required:	2.09
# Date created:		5th December 1994
# Whom:			gpalmer@FreeBSD.org
#
# $Id: Makefile,v 1.7 1995/04/12 20:31:23 asami Exp $
#

DISTNAME=	rxvt-2.09
CATEGORIES+=	x11
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/misc/

MAINTAINER=	gpalmer@FreeBSD.ORG

WRKSRC=		${WRKDIR}/rxvt
USE_IMAKE=	yes

# Get rid of the rclock directory until I can figure out how to patch
# that up also and make it!
pre-configure:
	@/bin/rm -rf ${WRKDIR}/rclock

.include <bsd.port.mk>
