# Created by: Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xkeywrap
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://hp.vector.co.jp/authors/VA014157/myfreesoft/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Record, repeat, and play key sequence from keyboard

MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	x11 xt
MAN1=		xkeywrap.1
MANCOMPRESSED=	yes

PORTDOCS=	README demo.dat xkeywrap_demo.c

PLIST_FILES=	bin/xkeywrap

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkeywrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xkeywrap.1.gz ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
