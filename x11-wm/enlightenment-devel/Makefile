# New ports collection makefile for:   enlightenment
# Version required:    0.12.3
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1997/09/14 19:54:23 max Exp $
#

DISTNAME=	enl_DR-0.12.3
PKGNAME=	enlightenment-0.12.3
CATEGORIES=	x11
MASTER_SITES=	http://www.rasterman.com/ftp/ \
		ftp://cthulhu.mandrake.net/pub/enlightenment/

MAINTAINER=	vanilla@MinJe.com.TW

LIB_DEPENDS=	Im\\.3\\.:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		tgatoppm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/enl

.include <bsd.port.mk>
