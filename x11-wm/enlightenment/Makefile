# New ports collection makefile for:   enlightenment
# Version required:    0.9
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	enl
PKGNAME=	enlightenment-0.9
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cse.unsw.edu.au/pub/users/s2154962/
DISTFILES=	enl_DR-0.9.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Im\\.1\\.:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
