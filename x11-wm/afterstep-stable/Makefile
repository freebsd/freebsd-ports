# New ports collection makefile for:	afterstep-stable
# Version required:	1.6.6
# Date created:		1 May 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.30 1999/01/17 03:03:44 billf Exp $
#

DISTNAME=	AfterStep-1.6.6
PKGNAME=	afterstep-1.6.6
CATEGORIES=     x11-wm afterstep
MASTER_SITES=   ftp://ftp.afterstep.org/stable/ \
		ftp://ftp.starshadow.com/pub/afterstep/stable/ \
		ftp://ftp.digex.net/pub/os/wm/AfterStep/stable/ \
		ftp://ftp.alpha1.net/pub/mirrors/ftp.afterstep.org/

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		png.2:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

INSTALL_TARGET=	install install.man
MAN1=	Animate.1x Audio.1x Auto.1x Banner.1x Cascade.1x Clean.1x \
	Form.1x Ident.1x Pager.1x Save.1x Script.1x Scroll.1x Tile.1x \
	Wharf.1x WinList.1x Zharf.1x afterstep.1x

NO_LATEST_LINK= yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}

.include <bsd.port.mk>
