# New ports collection makefile for:	afterstep-stable
# Version required:	1.6.10
# Date created:		1 May 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.33 1999/02/21 21:51:01 billf Exp $
#

DISTNAME=	AfterStep-${AS_VERSION}
PKGNAME=	afterstep-${AS_VERSION}
CATEGORIES=     x11-wm afterstep
MASTER_SITES=   ${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	stable

MAINTAINER=	dima@Chg.ru

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

AS_VERSION=	1.6.10
INSTALL_TARGET=	install install.man
MAN1=	Animate.1x Audio.1x Auto.1x Banner.1x Cascade.1x Clean.1x \
	Form.1x Ident.1x Pager.1x Save.1x Script.1x Scroll.1x Tile.1x \
	Wharf.1x WinList.1x Zharf.1x afterstep.1x

NO_LATEST_LINK= yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE} \
		--disable-save-windows \
		--enable-different-locknfeels

.include <bsd.port.mk>
