# New ports collection makefile for:	xfce
# Version required:	2.1.1
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.7 1998/10/05 05:18:01 steve Exp $
#

DISTNAME=	xfce-2.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	Nakai@technologist.com

BROKEN_ELF=	xforms is a.out only

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_GMAKE=	yes
USE_IMAKE=	yes

.include <bsd.port.mk>
