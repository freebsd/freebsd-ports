# New ports collection makefile for:   icewm
# Version required:    0.8.16
# Date created:        10 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.7 1998/05/02 21:22:55 vanilla Exp $
#

DISTNAME=	icewm-0.8.16
CATEGORIES=	x11
MASTER_SITES=	http://ixtas.fri.uni-lj.si/%7Emarkom/icewm/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes

pre-patch:
.if defined(TITLE_BOTTOM)
	${CP} ${FILESDIR}/patch-titlebottom ${PATCHDIR}/patch-ac
.else
	${CP} ${FILESDIR}/patch-titletop ${PATCHDIR}/patch-ac
.endif

post-install:
	${CP} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/lib/X11/icewm/taskbar

.include <bsd.port.mk>
