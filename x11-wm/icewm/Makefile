# New ports collection makefile for:   icewm
# Version required:    0.8.11
# Date created:        10 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/12/27 17:14:18 max Exp $
#

DISTNAME=	icewm-0.8.11
CATEGORIES=	x11
MASTER_SITES=	http://ixtas.fri.uni-lj.si/%7Emarkom/icewm/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X11=	yes

post-install:
	${CP} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/lib/X11/icewm/taskbar

.include <bsd.port.mk>
