# New ports collection makefile for:	props
# Version required:	1.0
# Date created:		3 January 1998
# Whom:			jraynard
#
# $Id$
#

DISTNAME=	props-1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.freebsd.org/~jraynard/ports/distfiles/

MAINTAINER=	jraynard@@freebsd.org

WRKSRC=		${WRKDIR}/props

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11/xview-lib

USE_IMAKE=	yes

post-install:
		${MKDIR} ${X11BASE}/lib/X11/locale/C/props; \
		${INSTALL_DATA} ${WRKSRC}/C/* ${X11BASE}/lib/X11/locale/C/props

.include <bsd.port.mk>
