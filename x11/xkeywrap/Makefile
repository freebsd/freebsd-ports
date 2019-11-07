# Created by: Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xkeywrap
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://ftp.vector.co.jp/18/98/1364/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Record, repeat, and play key sequence from keyboard

MAKE_ENV=	X11BASE="${LOCALBASE}"
USES=		xorg
USE_XORG=	x11 xt

PORTDOCS=	README
PORTEXAMPLES=	demo.dat xkeywrap_demo.c

PLIST_FILES=	bin/xkeywrap man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkeywrap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xkeywrap.1.gz ${STAGEDIR}${PREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S/^/${WRKSRC}\//} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
