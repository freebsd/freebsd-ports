# New ports collection makefile for:   qvwm
# Version required:    1.0b10a
# Date created:        2 January 1997
# Whom:                Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.16 1998/07/03 23:20:14 steve Exp $
#

DISTNAME=       qvwm-1.0b10a
CATEGORIES=     x11-wm
MASTER_SITES=   http://www-masuda.is.s.u-tokyo.ac.jp/~kourai/qvwm/program/

MAINTAINER=     Nakai@technologist.com

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=      yes
MAN1=		qvwm.1
MANCOMPRESSED=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/qvwm
	@ ${INSTALL_DATA} ${WRKSRC}/*.en ${PREFIX}/share/doc/qvwm
.endif

.include <bsd.port.mk>
