# New ports collection makefile for:   mlvwm
# Version required:    0.6.2
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/02/16 22:32:14 andreas Exp $
#

DISTNAME=	mlvwm-0.6.2
CATEGORIES=	x11
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/mlvwm/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

CONFIGURE_ENV=	X11BASE=${X11BASE}
USE_IMAKE=	yes

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${PREFIX}/lib/X11/mlvwm/pixmap

.include <bsd.port.mk>
