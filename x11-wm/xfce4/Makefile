# New ports collection makefile for:	xfce
# Version required:	1.2.4
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/12/10 22:48:22 vanilla Exp $
#

DISTNAME=	xfce-1.2.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/toolbars

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11-toolkits/xforms

WRKSRC=		${WRKDIR}/XFCE-1.2.4
USE_GMAKE=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf

.include <bsd.port.mk>
