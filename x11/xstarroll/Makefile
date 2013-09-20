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

USE_XORG=	xpm xt xaw
ALL_TARGET=	xstarroll

MAN1=		xstarroll.1
PLIST_FILES=	bin/xstarroll

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${LOCALBASE}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xstarroll ${PREFIX}/bin/xstarroll
	${INSTALL_MAN} ${WRKSRC}/xstarroll.man ${MANPREFIX}/man/man1/xstarroll.1

.include <bsd.port.mk>
