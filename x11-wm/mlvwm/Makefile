# New ports collection makefile for:   mlvwm
# Version required:    0.8.6
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.7 1998/03/11 07:31:11 vanilla Exp $
#

DISTNAME=	mlvwm-0.8.6
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/mlvwm/ \
		http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/
DISTFILES=	mlvwm-0.8.6.tar.gz mini-icons.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/mlvwm086
USE_IMAKE=	yes
EXTRACT_ONLY=	mlvwm-0.8.6.tar.gz

MAN1=		mlvwm.1

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/sample_rc/Mlvwm* ${PREFIX}/lib/X11/mlvwm
	${RM} -f ${PREFIX}/lib/X11/mlvwm/*.orig
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/mini-icons.tar.gz \
		-C ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_MAN} ${WRKSRC}/man/mlvwm.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
