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

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		$(WRKDIR)/xcolorsel
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xcolorsel.1

post-patch:
	${ECHO_CMD} "*.file: ${X11BASE}/lib/X11/rgb.txt" >> ${WRKSRC}/Xcolorsel.ad
	${PERL} -pi -e "s|#include <malloc.h>||g; s|/Xaw/|/Xaw3d/|g;" \
		${WRKSRC}/*.[ch]
	${PERL} -pi -e "s|app2head|./app2head|g; \
		s|XawClientLibs|-lXaw3d \\$$\(XMULIBONLY\) \\$$\(XTOOLLIB\) \\$$\(XPMLIB) \\$$\(XLIB\)|g" ${WRKSRC}/Imakefile

.include <bsd.port.mk>
