# New ports collection makefile for:	toolbox
# Version required:   	0.4.2
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	toolbox-0.4.2
CATEGORIES=	misc
MASTER_SITES=	http://cs.bc.edu/~kelleyry/blackbox/utils/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolbox ${PREFIX}/bin/toolbox

.include <bsd.port.mk>
