# New ports collection makefile for:	WindowMaker
# Version required:	0.6.3
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $Id$
#

DISTNAME=	WindowMaker-0.6.3
PKGNAME=	windowmaker-0.6.3
CATEGORIES=	x11
MASTER_SITES=	http://isolation.ml.org/oxygen/wm/bin/ \
		ftp://wm.wep.net/pub/WindowMaker/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
STRIP=

.include <bsd.port.mk>
