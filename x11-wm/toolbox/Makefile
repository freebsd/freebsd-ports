# New ports collection makefile for:	toolbox
# Version required:   	0.4.6
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	toolbox-0.4.6
CATEGORIES= 	x11-wm
MASTER_SITES=	http://www2.bc.edu/~kelleyry/toolbox/

MAINTAINER=	cpiazza@FreeBSD.org

USE_QT2=	yes
USE_NEWGCC=	yes
USE_X_PREFIX=	yes

MAKE_ENV=	CXX="${CXX}" CC="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolbox ${PREFIX}/bin/toolbox

.include <bsd.port.mk>
