# New ports collection makefile for:	x3270
# Version required:	3.1.1.6
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$
#

DISTNAME=	x3270-3.1.1.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=     volf@oasis.IAEhv.nl

WRKSRC=		${WRKDIR}/x3270-3.1.1
USE_IMAKE=	yes
MAN1=		x3270.1 x3270if.1 x3270-script.1 ibm_hosts.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

pre-install:
.if !exists(${X11BASE}/lib/X11/fonts/local)
	@${ECHO} "*********************************************************"
	@${ECHO} "Please update your XFree86 to version 3.3.3 or later"
	@${ECHO} "or add ${X11BASE}/lib/X11/fonts/local to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "*********************************************************"
.endif

.include <bsd.port.post.mk>
