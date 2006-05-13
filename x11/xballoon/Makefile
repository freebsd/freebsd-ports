# New ports collection makefile for:   XBalloon
# Date created:        3 March 1999
# Whom:                Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xballoon
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.saturn.dti.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Balloons move on root window

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	xballoon

MAN1=		xballoon.1
PLIST_FILES=	bin/xballoon

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${X11BASE}|g ; \
		 s|gcc |$${CC} |g ; \
		 s|-O |$${CFLAGS} |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xballoon ${PREFIX}/bin/xballoon
	${INSTALL_MAN} ${WRKSRC}/xballoon.man ${MANPREFIX}/man/man1/xballoon.1

.include <bsd.port.mk>
