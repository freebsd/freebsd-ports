# Created by: Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xmangekyou
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://ftp.vector.co.jp/16/65/1309/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kaleidoscope on X

USES=		xorg
USE_XORG=	x11 xpm xaw
ALL_TARGET=	xmangekyou

PORTDOCS=	COPYRIGHT.euc HISTORY.euc README.euc
PLIST_FILES=	bin/xmangekyou lib/X11/XMangekyou/animation.dat \
		man/man1/xmangekyou.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|= /usr/X11R6|= $${PREFIX}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g ; \
		 s|-I/usr/X11R6/|-I$${LOCALBASE}/|g ; \
		 s|-L/usr/X11R6/|-L$${LOCALBASE}/|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmangekyou ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmangekyou.1.gz ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/XMangekyou
	${INSTALL_DATA} ${WRKSRC}/animation.dat ${STAGEDIR}${PREFIX}/lib/X11/XMangekyou

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.euc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
