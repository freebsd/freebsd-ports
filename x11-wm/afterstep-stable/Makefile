# New ports collection makefile for:	afterstep-1.6
# Version required:	1.6
# Date created:		1 May 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.28 1998/12/23 01:41:18 steve Exp $
#

DISTNAME=	AfterStep-1.6.0
CATEGORIES=     x11-wm
MASTER_SITES=   ftp://ftp.afterstep.org/stable/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		png.2:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

BROKEN=		upgrade

INSTALL_TARGET=	install install.man
MAN1=	Animate.1x Audio.1x Auto.1x Banner.1x Cascade.1x Clean.1x \
	Form.1x Ident.1x Pager.1x Save.1x Script.1x Scroll.1x Tile.1x \
	Wharf.1x WinList.1x Zharf.1x afterstep.1x

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}

.include <bsd.port.mk>
