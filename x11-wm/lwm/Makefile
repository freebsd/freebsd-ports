# Created by: J Han <hjh@photino.com>
# $FreeBSD$

PORTNAME=	lwm
PORTVERSION=	1.2.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.jfc.org.uk/files/lwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight window manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig xorg
USE_XORG=	sm x11 xext
MAKEFILE=	no_xmkmf_makefile
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

CFLAGS+=	`pkg-config --cflags sm x11 xext ice` -DSHAPE
LDFLAGS+=	`pkg-config --libs sm x11 xext ice`

PORTDOCS=	AUTHORS BUGS ChangeLog README TODO
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
