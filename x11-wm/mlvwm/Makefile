# New ports collection makefile for:   mlvwm
# Version required:    0.8.9
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.12 1998/12/23 01:33:52 steve Exp $
#

DISTNAME=	mlvwm089
PKGNAME=	mlvwm-0.8.9
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/mlvwm/ \
		http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/
DISTFILES=	mlvwm089.tgz mini-icons.tar.gz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/mlvwm089
USE_IMAKE=	yes
EXTRACT_ONLY=	mlvwm089.tgz
MAN1=		mlvwm.1
MANCOMPRESSED=	no

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${PREFIX}/lib/X11/mlvwm/pixmap
	${INSTALL_DATA} ${WRKSRC}/sample_rc/Mlvwm* ${PREFIX}/lib/X11/mlvwm
	${RM} -f ${PREFIX}/lib/X11/mlvwm/*.orig
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/mini-icons.tar.gz \
		-C ${PREFIX}/lib/X11/mlvwm/pixmap
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/man/mlvwm.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
