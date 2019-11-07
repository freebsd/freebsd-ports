# Created by: Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xballoon
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Balloons move on root window

USES=		xorg
USE_XORG=	xpm xmu xaw
ALL_TARGET=	xballoon

PLIST_FILES=	bin/xballoon \
		man/man1/xballoon.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${LOCALBASE}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xballoon ${STAGEDIR}${PREFIX}/bin/xballoon
	${INSTALL_MAN} ${WRKSRC}/xballoon.man ${STAGEDIR}${MANPREFIX}/man/man1/xballoon.1

.include <bsd.port.mk>
