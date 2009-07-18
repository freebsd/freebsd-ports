# New ports collection makefile for:	electricsheep
# Date created:				11 Feb 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	electricsheep
PORTVERSION=	2.6.8
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://electricsheep.org/

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	A nice distributed screensaver

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		xsetbg:${PORTSDIR}/x11/xloadimage \
		curl:${PORTSDIR}/ftp/curl

MAKE_JOBS_SAFE=	yes

USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_XORG=	x11 xau xdmcp xext xi xrandr xv sm ice

MAN1=		electricsheep.1

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

LIBTOOLFILES=	configure mpeg2dec/configure flam3/configure

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6/lib/xscreensaver/config|${LOCALBASE}/share/xscreensaver/config|' \
		${WRKSRC}/Makefile.in

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
	@${INSTALL_MAN} ${WRKSRC}/electricsheep.man ${PREFIX}/man/man1/electricsheep.1

.include <bsd.port.post.mk>
