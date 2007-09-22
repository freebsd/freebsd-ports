# Ports collection makefile for:	transset-df
# Date created:				2005-09-21
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	transset-df
PORTVERSION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://forchheimer.se/transset-df/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Make your windows transparent

USE_X_PREFIX=	yes
ALL_TARGET=	transset-df
MAKE_ARGS=	CFLAGS="${CFLAGS}"
USE_GETOPT_LONG=yes

PLIST_FILES=	bin/transset-df

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=		requires X.Org; install x11/xorg and try again
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/transset-df ${PREFIX}/bin

.include <bsd.port.post.mk>
