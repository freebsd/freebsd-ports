# New ports collection makefile for:	neXtaw
# Version required:	0.5
# Date created:		16 January 1997
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.4 1997/07/17 15:13:01 max Exp $
#

DISTNAME=	neXtaw-0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/X

MAINTAINER=	tg@FreeBSD.ORG

USE_IMAKE=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/X11

post-configure:
	@${ECHO_MSG} "*********************************************************************"
	@${ECHO_MSG} "* Don't worry about the warning messages above, the port will build *"
	@${ECHO_MSG} "*********************************************************************"
	@cd ${WRKSRC}/exports/include/X11/neXtaw; ln -sf ../../../../*.h .

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
