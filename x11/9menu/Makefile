# Created by: Eric L. Hernes <erich@rrnet.com>
# $FreeBSD$

PORTNAME=	9menu
PORTVERSION=	1.10
DISTVERSIONPREFIX=	${PORTNAME}-release-
CATEGORIES=	x11 plan9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple menu patterned after Plan9

LICENSE=	9MENU
LICENSE_NAME=	9menu License
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	arnoldrobbins
USE_XORG=	x11

MAKEFILE=	Makefile.noimake
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LIBS="${LIBS} -lX11"
ALL_TARGET=	9menu
PLIST_FILES=	bin/9menu \
		share/man/man1/9menu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
