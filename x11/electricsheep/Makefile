# New ports collection makefile for:	electricsheep
# Date created:				11 Feb 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	electricsheep
PORTVERSION=	2.6.2
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://electricsheep.org/
DISTNAME=	${PORTNAME}-2.6.2

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A nice distributed screensaver

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		xsetbg:${PORTSDIR}/x11/xloadimage \
		curl:${PORTSDIR}/ftp/curl

.if defined(WITH_XSCREENSAVER)
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-2.6.2

USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_REINPLACE=	yes
USE_LIBTOOL_VER=13

.if !defined(NOPORTDOCS)
MAN1=		electricsheep.1
.endif

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

LIBTOOLFILES=	configure mpeg2dec/configure flam3/configure

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_XSCREENSAVER)
	@${ECHO_MSG} "elecricsheep has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_XSCREENSAVER=yes Installs configuration file"
	@${ECHO_MSG} "                      for XScreenSaver"
	@${ECHO_MSG} ""
.endif

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
		's|/usr/local/share|${DATADIR}|' \
		${WRKSRC}/electricsheep.c

	@${REINPLACE_CMD} -e \
		's|-Wall||; \
		s|CFLAGS=\$$OPT_CFLAGS|#CFLAGS=\$$OPT_CFLAGS|' \
		${WRKSRC}/mpeg2dec/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/electricsheep ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/electricsheep-voter ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-animate ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-convert ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-genome ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-render ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mpeg2dec/src/mpeg2dec_onroot ${PREFIX}/bin
	@${INSTALL} -d -m 0755 ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.tif ${DATADIR}
.if defined(WITH_XSCREENSAVER)
	@${INSTALL_DATA} ${WRKSRC}/electricsheep.xml ${PREFIX}/share/xscreensaver/config
.endif
.if !defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/electricsheep.man ${PREFIX}/man/man1/electricsheep.1
.endif

.include <bsd.port.post.mk>

