PORTNAME=	lwm
PORTVERSION=	1.2.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.jfc.org.uk/files/lwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight window manager
WWW=		https://www.jfc.org.uk/software/lwm.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Last upstream release was in 2016
EXPIRATION_DATE=	2024-01-18

USES=		pkgconfig xorg
USE_XORG=	sm x11 xext

MAKEFILE=	no_xmkmf_makefile
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

CFLAGS+=	`pkg-config --cflags sm x11 xext ice` -DSHAPE
LDFLAGS+=	`pkg-config --libs sm x11 xext ice`

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS BUGS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
