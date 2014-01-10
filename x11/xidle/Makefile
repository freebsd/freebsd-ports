# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xidle
PORTVERSION=	24102005
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Run a program on X inactivity

USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include -D__dead=static
MAKE_ARGS+=	X11LIBDIR="${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USE_XORG=	x11 xscrnsaver
PLIST_FILES=	bin/xidle man/man1/xidle.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xidle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xidle.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
