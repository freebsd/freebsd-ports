# New ports collection makefile for:	ecore
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	0.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ishmael27x@yahoo.com

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-install:
	@strip ${PREFIX}/lib/libecore.so.0

.include <bsd.port.mk>
