# New ports collection makefile for:	xcalib
# Date created:				5 April 2005
# Whom:					Petr Holub <hopet@ics.muni.cz>
#
# $FreeBSD$
#

PORTNAME=	xcalib
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	x11 graphics
MASTER_SITES=	http://www.etg.e-technik.uni-erlangen.de/web/doe/xcalib/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	A program for display calibration of X11-Servers with ICC profiles

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README README.profilers
USE_XORG=	x11 xext sm xxf86vm

DEFINES=	-DXCALIB_VERSION=\"${PORTVERSION}\" -DUNIX
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib -lm -lX11 -lXxf86vm -lXext
CFLAGS+=	-I./icclib -I${LOCALBASE}/include -I${LOCALBASE}/include

do-build:
	${CC} ${CFLAGS} ${DEFINES} -c ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}.o
	${CC} ${CFLAGS} ${DEFINES} -c ${WRKSRC}/icclib/icc.c -o ${WRKSRC}/icclib/icc.o
	${CC} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.o -o ${WRKSRC}/${PORTNAME}

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
