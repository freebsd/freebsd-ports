# New ports collection makefile for:	neXtaw
# Version required:	0.5
# Date created:		16 January 1997
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1997/01/20 07:15:18 tg Exp $
#

DISTNAME=	neXtaw-0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/X

MAINTAINER=	tg@FreeBSD.ORG

USE_IMAKE=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/X11

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
