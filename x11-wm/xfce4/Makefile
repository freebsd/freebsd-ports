# New ports collection makefile for:	xfce
# Version required:	2.4.0
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.15 1999/03/31 15:52:31 steve Exp $
#

DISTNAME=	xfce-2.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_IMAKE=	yes

MAN1=	xfce.1 xfmouse.1 xfpager.1 xfsound.1 xfwm.1

.include <bsd.port.mk>
