# New ports collection Makefile for: rxvt
# Version required:	2.09
# Date created:		5th December 1994
# Whom:			gpalmer@FreeBSD.org
#
# $Id: Makefile,v 1.5 1995/02/01 22:38:08 gpalmer Exp $
#

DISTNAME=	rxvt-2.09
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/rxvt
PREFIX=		/usr/X11R6
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/misc/
CATEGORIES+=	x11
MAINTAINER=	gpalmer@FreeBSD.ORG

# Get rid of the rclock directory until I can figure out how to patch
# that up also and make it!
pre-configure:
	@/bin/rm -rf ${WRKDIR}/rclock

.include <bsd.port.mk>
