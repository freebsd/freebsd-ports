# New ports collection makefile for:	WindowMaker
# Version required:	0.16.0
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.14 1998/06/15 14:40:43 tg Exp $

DISTNAME=	WindowMaker-0.16.0
PKGNAME=	windowmaker-0.16.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/

MAINTAINER=	handy@physics.montana.edu

BUILD_DEPENDS=	${PREFIX}/lib/libPropList.a:${PORTSDIR}/devel/libproplist
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		png\\.2\\.:${PORTSDIR}/graphics/png \
		tiff34\\.1:${PORTSDIR}/graphics/tiff34

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${LOCALBASE}/lib/locale \
	--with-gfx-libs=-L${LOCALBASE}/lib \
	--with-gfx-incs="-I${LOCALBASE}/include/tiff34 -I${LOCALBASE}/include"

.include <bsd.port.mk>
