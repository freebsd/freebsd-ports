# Created by: Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xstarroll
PORTVERSION=	1.1b
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Letters fly to far, far, far away

WRKSRC=		${WRKDIR}/${PORTNAME}-1.1

USES=		xorg
USE_XORG=	xpm xt xaw
ALL_TARGET=	xstarroll

PLIST_FILES=	bin/xstarroll \
		man/man1/xstarroll.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${LOCALBASE}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xstarroll ${STAGEDIR}${PREFIX}/bin/xstarroll
	${INSTALL_MAN} ${WRKSRC}/xstarroll.man ${STAGEDIR}${MANPREFIX}/man/man1/xstarroll.1

.include <bsd.port.mk>
