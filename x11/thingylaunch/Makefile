# New ports collection makefile for:	thingylaunch
# Date created:				1 October 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	thingylaunch
PORTVERSION=	1.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}/gahr/ \
		http://people.freebsd.org/~gahr/distfiles/ \
		http://www.gahr.ch/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A lightweight tab-completing launcher for X

USE_XORG=	x11 xproto
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
