# New ports collection makefile for:   mlvwm
# Version required:    0.6.2
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	mlvwm-0.6.2
CATEGORIES=	x11
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/mlvwm/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

CONFIGURE_ENV=	X11BASE=${X11BASE}

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
USE_IMAKE=	yes

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${PREFIX}/lib/X11/mlvwm/pixmap

.include <bsd.port.mk>
