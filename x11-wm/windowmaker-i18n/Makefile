# New ports collection makefile for:	WindowMaker
# Version required:	0.20.1
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.33 1998/09/27 20:59:11 steve Exp $

DISTNAME=	WindowMaker-0.20.1
PKGNAME=	windowmaker-0.20.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	handy@physics.montana.edu

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff34.1:${PORTSDIR}/graphics/tiff34

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${LOCALBASE}/lib/locale \
	--with-gfx-libs="-L${LOCALBASE}/lib" \
	--with-gfx-incs="-I${LOCALBASE}/include/tiff34 -I${LOCALBASE}/include"

MAN1=	geticonset.1x getstyle.1x seticons.1x setstyle.1x \
	wdwrite.1x wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

DATAFILES=	WindowMaker-data.tar.gz

post-extract:
	cd ${WRKSRC}; ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} libPropList.tar.gz

pre-configure:
	@(cd ${WRKSRC}/libPropList && CC="${CC}" CXX="${CXX}" \
	    ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS} -fPIC" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	    ${MAKE} ${MAKE_ENV})

pre-install:
	@(cd ${WRKSRC}/libPropList; ${MAKE} ${MAKE_ENV} install)

post-install:
	${MKDIR} ${PREFIX}/share/WindowMaker/Pixmaps/
	${INSTALL_DATA} ${WRKDIR}/WindowMaker-data/pixmaps/* \
		${PREFIX}/share/WindowMaker/Pixmaps/
	if [ "${PORTOBJFORMAT}" = "elf" ]; then \
		${LN} -sf libPropList.so.0 ${PREFIX}/lib/libPropList.so; \
	else \
		${LN} -sf libPropList.so.0.8 ${PREFIX}/lib/libPropList.so; \
	fi
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
