# New ports collection makefile for:	toolbox
# Version required:   	0.4.3
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.2 1999/06/14 03:09:47 jseger Exp $
#

DISTNAME=	toolbox-0.4.3
CATEGORIES=	misc
MASTER_SITES=	http://cs.bc.edu/~kelleyry/blackbox/utils/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolbox ${PREFIX}/bin/toolbox

.include <bsd.port.mk>
