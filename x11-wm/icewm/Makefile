# New ports collection makefile for:   icewm
# Version required:    0.8.12
# Date created:        10 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1998/02/20 04:22:12 steve Exp $
#

DISTNAME=	icewm-0.8.12
CATEGORIES=	x11
MASTER_SITES=	http://ixtas.fri.uni-lj.si/%7Emarkom/icewm/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X11=	yes

post-install:
	${CP} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/lib/X11/icewm/taskbar

.include <bsd.port.mk>
