# New ports collection makefile for:	WindowMaker
# Version required:	0.13.1
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.1.1.1 1997/11/04 10:33:43 tg Exp $

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
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-nlsdir=${LOCALBASE}/lib/locale

.include <bsd.port.mk>
