# Created by: Wayne Cuddy <wayne@crb-web.com>
# $FreeBSD$

PORTNAME=	xcolorsel
PORTVERSION=	1.1a
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/utilities
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X utility to translate rgb values into X color names

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/01-COPYING

BROKEN=		segfaults when trying to actually grab color

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d
RUN_DEPENDS=	rgb>=1.0.3:x11/rgb

WRKSRC=		${WRKDIR}/xcolorsel
USES=		imake xorg
USE_XORG=	xpm

post-patch:
	@${ECHO_CMD} "*.file: ${LOCALBASE}/lib/X11/rgb.txt" >> ${WRKSRC}/Xcolorsel.ad
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||g' \
		-e 's|/Xaw/|/Xaw3d/|g' ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e 's|app2head|./app2head|g' \
		-e 's|XawClientLibs|-lXaw3d $$(XMULIBONLY) $$(XTOOLLIB) $$(XPMLIB) $$(XLIB)|g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
