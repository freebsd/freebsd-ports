# New ports collection makefile for:   mlvwm
# Version required:    0.7.1
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/02/19 06:34:57 asami Exp $
#

DISTNAME=	mlvwm-0.7.1
CATEGORIES=	x11
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/mlvwm/ \
		http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/
DISTFILES=	mlvwm-0.7.1.tar.gz mini-icons.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
EXTRACT_ONLY=	mlvwm-0.7.1.tar.gz

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/sample_rc/Mlvwm* ${PREFIX}/lib/X11/mlvwm
	${RM} -f ${PREFIX}/lib/X11/mlvwm/*.orig
	tar xzvf ${DISTDIR}/${DIST_SUBDIR}/mini-icons.tar.gz \
		-C ${PREFIX}/lib/X11/mlvwm/pixmap

.include <bsd.port.mk>
