# New ports collection makefile for:	electricsheep
# Date created:				11 Feb 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	electricsheep
PORTVERSION=	2.4
CATEGORIES=	x11
MASTER_SITES=	http://electricsheep.org/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A nice distributed screensaver

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		xsetbg:${PORTSDIR}/graphics/xli \
		curl:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
USE_SDL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

LIBTOOLFILES=	configure mpeg2dec/configure flame/configure

post-patch:
	@${REINPLACE_CMD} -e \
		's|sdl-config|sdl11-config|' \
		${WRKSRC}/mpeg2dec/configure

	@${REINPLACE_CMD} -e \
		's|/usr/X11R6/lib/xscreensaver/config|${X11BASE}/share/xscreensaver/config|' \
		${WRKSRC}/Makefile.in

	@${REINPLACE_CMD} -e \
		's|<SDL/SDL.h>|<SDL11/SDL.h>|' \
		${WRKSRC}/mpeg2dec/libvo/video_out_sdl.c

	@${REINPLACE_CMD} -e \
		's|/usr/local/share|${PREFIX}/share/electricsheep|' \
		${WRKSRC}/electricsheep.c

	@${REINPLACE_CMD} -e \
		's|-Wall||; \
		s|CFLAGS=\$$OPT_CFLAGS|#CFLAGS=\$$OPT_CFLAGS|' \
		${WRKSRC}/mpeg2dec/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/electricsheep ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/anim-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/convert-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/hqi-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/pick-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mpeg2dec/src/mpeg2dec_onroot ${PREFIX}/bin
	@${INSTALL} -d -m 0755 ${PREFIX}/share/electricsheep
	@${INSTALL_DATA} ${WRKSRC}/*.tif ${PREFIX}/share/electricsheep

.include <bsd.port.mk>
