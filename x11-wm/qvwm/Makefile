# New ports collection makefile for:   qvwm
# Version required:    1.0b6a
# Date created:        2 Januruary 1997
# Whom:                Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1997/01/19 18:48:17 jfitz Exp $
#

DISTNAME=       qvwm-1.0b6
CATEGORIES=     x11
MASTER_SITES=   http://www-masuda.is.s.u-tokyo.ac.jp/~kourai/qvwm/program/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	qvwm-1.0b6a.diff.gz
PATCH_DIST_STRIP=       -p1

MAINTAINER=     Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

DIST_SUBDIR=	qvwm
CONFIGURE_ENV=  X11BASE=${X11BASE}
USE_IMAKE=      yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} -p ${PREFIX}/share/doc/qvwm
	@ ${INSTALL_DATA} ${FILESDIR}/*.en ${PREFIX}/share/doc/qvwm
.endif

.include <bsd.port.mk>
