# New ports collection makefile for:	toolbox
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	toolbox
PORTVERSION=	0.4.6
CATEGORIES=	x11-wm
MASTER_SITES=	http://www2.bc.edu/~kelleyry/toolbox/

MAINTAINER=	ports@FreeBSD.org

USE_QT_VER=	2
USE_X_PREFIX=	yes

MAKE_ENV=	CXX="${CXX}" CC="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolbox ${PREFIX}/bin/toolbox

.include <bsd.port.mk>
