PORTNAME=	xidle
PORTVERSION=	26052015
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	LOCAL/novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Run a program on X inactivity

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 xorg
CFLAGS+=	-I${LOCALBASE}/include -D__dead=static
MAKE_ARGS+=	X11BASE="${LOCALBASE}" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USE_XORG=	x11 xscrnsaver xcb xau xdmcp xext
PLIST_FILES=	bin/xidle share/man/man1/xidle.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xidle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xidle.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
