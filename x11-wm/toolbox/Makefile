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
COMMENT=	A blackbox style configuration utility

USE_QT_VER=	2
USE_X_PREFIX=	yes

MAKE_ENV=	CXX="${CXX}" CC="${CC}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Fails to link"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolbox ${PREFIX}/bin/toolbox

.include <bsd.port.post.mk>
