# New ports collection makefile for:	thingylaunch
# Date created:				1 October 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	thingylaunch
PORTVERSION=	1.1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}/gahr/ \
		http://people.freebsd.org/~gahr/distfiles/ \
		http://www.gahr.ch/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A lightweight tab-completing launcher for X

USE_XORG=	x11 xproto
USE_GNOME=	pkgconfig
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
