# Ports collection makefile for:	transset-df
# Date created:				2005-09-21
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	transset-df
PORTVERSION=	6
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://forchheimer.se/transset-df/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Make your windows transparent

ALL_TARGET=	transset-df
MAKE_ARGS=	CFLAGS="${CFLAGS}"
USE_XORG=	x11 xfixes xcomposite xrender xdamage
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/transset-df

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/transset-df ${PREFIX}/bin

.include <bsd.port.post.mk>
