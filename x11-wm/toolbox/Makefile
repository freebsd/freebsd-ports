# New ports collection makefile for:	toolbox
# Version required:   	0.4.6
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	toolbox-0.4.6
CATEGORIES= 	x11-wm
MASTER_SITES=	http://rfk.masslinux.com/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	qt2.2:${PORTSDIR}/x11-toolkits/qt201

USE_NEWGCC=	yes
USE_X_PREFIX=	yes

MAKE_ENV=	CXX="${CXX}" CC="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolbox ${PREFIX}/bin/toolbox

.include <bsd.port.mk>
