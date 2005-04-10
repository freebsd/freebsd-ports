# New ports collection makefile for:	xcolorsel
# Date Created:			11 November 1998
# Whom:				Wayne Cuddy <wayne@crb-web.com>
#
# $FreeBSD$
#

PORTNAME=	xcolorsel
PORTVERSION=	1.1a
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
DISTNAME=	${PKGNAME}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X utility to translate rgb values into X color names

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		$(WRKDIR)/xcolorsel
USE_REINPLACE=	yes
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xcolorsel.1

post-patch:
	@${ECHO_CMD} "*.file: ${X11BASE}/lib/X11/rgb.txt" >> ${WRKSRC}/Xcolorsel.ad
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||g' \
		-e 's|/Xaw/|/Xaw3d/|g' ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e 's|app2head|./app2head|g' \
		-e 's|XawClientLibs|-lXaw3d $$(XMULIBONLY) $$(XTOOLLIB) $$(XPMLIB) $$(XLIB)|g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
