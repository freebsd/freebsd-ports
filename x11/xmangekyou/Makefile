# New ports collection makefile for:	XMangekyou
# Date created:		30 October 1998
# Whom:			Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xmangekyou
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://hp.vector.co.jp/authors/VA014157/myfreesoft/ \
		ftp://ftp.vector.co.jp/pack/unix/art/anime/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A kaleidoscope on X

ALL_TARGET=	xmangekyou

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		xmangekyou.1
MANCOMPRESSED=	yes
PORTDOCS=	COPYRIGHT.euc HISTORY.euc README.euc
PLIST_FILES=	bin/xmangekyou lib/X11/XMangekyou/animation.dat
PLIST_DIRS=	lib/X11/XMangekyou

post-patch:
	@${REINPLACE_CMD} -e 's|= /usr/X11R6|= $${PREFIX}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g ; \
		 s|-I/usr/X11R6/|-I$${X11BASE}/|g ; \
		 s|-L/usr/X11R6/|-L$${X11BASE}/|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmangekyou ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmangekyou.1.gz ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/X11/XMangekyou
	${INSTALL_DATA} ${WRKSRC}/animation.dat ${PREFIX}/lib/X11/XMangekyou
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.euc ${DOCSDIR}
.endif

.include <bsd.port.mk>
