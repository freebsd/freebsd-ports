# New ports collection makefile for:	neXtaw
# Version required:	0.5
# Date created:		16 January 1997
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id$
#

DISTNAME=	neXtaw-0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	Incoming

MAINTAINER=	tg@FreeBSD.ORG

USE_IMAKE=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/X11

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
