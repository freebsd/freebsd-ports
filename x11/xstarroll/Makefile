# New ports collection makefile for:   XStarRoll
# Date created:        14 January 1999
# Whom:                Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xstarroll
PORTVERSION=	1.1b
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.saturn.dti.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Letters fly to far, far, far away

WRKSRC=		${WRKDIR}/${PORTNAME}-1.1

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	xstarroll

MAN1=		xstarroll.1
PLIST_FILES=	bin/xstarroll

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${X11BASE}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xstarroll ${PREFIX}/bin/xstarroll
	${INSTALL_MAN} ${WRKSRC}/xstarroll.man ${MANPREFIX}/man/man1/xstarroll.1

.include <bsd.port.mk>
