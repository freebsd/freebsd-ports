# New ports collection makefile for:	WindowMaker
# Version required:	0.20.3
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.41 1998/12/04 07:53:41 tg Exp $

DISTNAME=	WindowMaker-0.20.3
PKGNAME=	windowmaker-0.20.3
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${LOCALBASE}/lib/locale \
	--with-gfx-libs="-L${LOCALBASE}/lib" \
	--with-gfx-incs="-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
	--disable-debug

MAN1=	geticonset.1x getstyle.1x seticons.1x setstyle.1x \
	wdwrite.1x wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

DATAFILES=	WindowMaker-data.tar.gz

post-patch:
	@perl -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c

post-install:
	${MKDIR} ${PREFIX}/share/WindowMaker/Pixmaps/
	${INSTALL_DATA} ${WRKDIR}/WindowMaker-data/pixmaps/* \
		${PREFIX}/share/WindowMaker/Pixmaps/

.include <bsd.port.mk>
