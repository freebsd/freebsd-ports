# New ports collection makefile for:	WindowMaker
# Version required:	0.13.1
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.2 1998/02/24 09:16:48 tg Exp $

DISTNAME=	WindowMaker-0.13.1
PKGNAME=	windowmaker-0.13.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/wmaker/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/linux/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/

MAINTAINER=	handy@physics.montana.edu

BUILD_DEPENDS=	${PREFIX}/lib/libPropList.a:${PORTSDIR}/devel/libproplist
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		tiff34\\.1:${PORTSDIR}/graphics/tiff34

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${LOCALBASE}/lib/locale \
	--with-gfx-libs=-L${LOCALBASE}/lib \
	--with-gfx-incs="-I${LOCALBASE}/include/tiff34 -I${LOCALBASE}/include"

.include <bsd.port.mk>
