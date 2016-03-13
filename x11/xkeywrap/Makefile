# Created by: Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xkeywrap
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://hp.vector.co.jp/authors/VA014157/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Record, repeat, and play key sequence from keyboard

BROKEN=		unfetchable
DEPRECATED=	Does not fetch
EXPIRATION_DATE=2016-04-13

MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	x11 xt

PORTDOCS=	README demo.dat xkeywrap_demo.c

PLIST_FILES=	bin/xkeywrap man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkeywrap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xkeywrap.1.gz ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
