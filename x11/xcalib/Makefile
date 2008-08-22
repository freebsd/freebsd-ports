# New ports collection makefile for:	xcalib
# Date created:				5 April 2005
# Whom:					Petr Holub <hopet@ics.muni.cz>
#
# $FreeBSD$
#

PORTNAME=	xcalib
PORTVERSION=	0.8
CATEGORIES=	x11 graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	A program for display calibration of X11-Servers with ICC profiles

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README README.profilers
USE_XORG=	x11 xext sm xxf86vm
USE_GMAKE=	yes

DEFINES=	-DXCALIB_VERSION=\"${PORTVERSION}\" -DUNIX
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib -lm -lX11 -lXxf86vm -lXext
CFLAGS+=	-I./icclib -I${LOCALBASE}/include -I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.icc ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
