# New ports collection makefile for:	electricsheep
# Date created:				11 Feb 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	electricsheep
PORTVERSION=	2.1
CATEGORIES=	x11
MASTER_SITES=	http://www-2.cs.cmu.edu/~spot/cache/

MAINTAINER=	dyeske@yahoo.com

FORBIDDEN=	"domain is no longer under author's control <URL:http://draves.org/electricsheep/>"

RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		xsetbg:${PORTSDIR}/graphics/xli \
		curl:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share/electricsheep|g; \
		s|setpgrp()|setpgrp(getpid(), getpid())|g' \
		${WRKSRC}/electricsheep.c
	@${REINPLACE_CMD} -e 's|/usr/include/X11|${X11BASE}/include|g; \
		s|-I/usr/include||g; \
		s|gcc|${CC}|g; \
		s|^CC|#CC|g; \
		s|/usr/lib/libjpeg.so.62||g' \
		${WRKSRC}/video_out/Makefile
	@${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|g' \
		${WRKSRC}/flame/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/electricsheep ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flame/anim-flame ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flame/pick-flame ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/video_out/mpeg_play ${PREFIX}/bin/mpeg-loop
	${INSTALL} -d -m 0755 ${PREFIX}/share/electricsheep
	${INSTALL_DATA} ${WRKSRC}/*.tif ${PREFIX}/share/electricsheep

.include <bsd.port.mk>
