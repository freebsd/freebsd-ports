# New ports collection makefile for:	WindowMaker
# Version required:	0.17.5
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.17 1998/07/28 06:17:29 tg Exp $

DISTNAME=	WindowMaker-0.17.5
PKGNAME=	windowmaker-0.17.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		png\\.2\\.:${PORTSDIR}/graphics/png \
		tiff34\\.1:${PORTSDIR}/graphics/tiff34

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${LOCALBASE}/lib/locale \
	--with-gfx-libs="-L${LOCALBASE}/lib -ltiff34" \
	--with-gfx-incs="-I${LOCALBASE}/include/tiff34 -I${LOCALBASE}/include"

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
	    make)

pre-install:
	@(cd ${WRKSRC}/libPropList; ${MAKE} install)

.include <bsd.port.mk>
