# New ports collection makefile for:	xidle
# Date created:				2005-10-24
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xidle
PORTVERSION=	24102005
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Run a program on X inactivity

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
CFLAGS+=	-I${X11BASE}/include -D__dead=static
MAKE_ARGS+=	X11LIBDIR="${X11BASE}/lib" \
		CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/xidle
MAN1=		xidle.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xidle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xidle.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
