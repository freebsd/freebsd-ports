# New ports collection makefile for:	xfce
# Version required:	2.4.0
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.13 1999/01/12 16:51:20 vanilla Exp $
#

DISTNAME=	xfce-2.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

# depends on xforms
ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_IMAKE=	yes

.include <bsd.port.mk>
