# New ports collection makefile for:   icewm
# Version required:    0.9.12
# Date created:        10 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.14 1998/08/07 23:01:39 asami Exp $
#

DISTNAME=	icewm-0.9.12
CATEGORIES=	x11-wm
MASTER_SITES=	http://berta.fri.uni-lj.si/~markom/icewm/devel/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

pre-patch:
.if defined(TITLE_BOTTOM)
	${CP} ${FILESDIR}/patch-titlebottom ${PATCHDIR}/patch-ac
.else
	${CP} ${FILESDIR}/patch-titletop ${PATCHDIR}/patch-ac
.endif
	${CP} ${FILESDIR}/MakeConfig.FreeBSD ${WRKSRC}/src

post-install:
	${CP} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/lib/X11/icewm/taskbar

.include <bsd.port.mk>
