# New ports collection makefile for:   qvwm
# Version required:    1.0b9c
# Date created:        2 January 1997
# Whom:                Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.10 1998/01/07 02:00:19 jfieber Exp $
#

DISTNAME=       qvwm-1.0b9c
CATEGORIES=     x11
MASTER_SITES=   http://www-masuda.is.s.u-tokyo.ac.jp/~kourai/qvwm/program/

MAINTAINER=     Nakai@Mlab.t.u-tokyo.ac.jp

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
