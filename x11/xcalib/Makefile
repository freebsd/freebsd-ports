# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	xcalib
PORTVERSION=	0.8
CATEGORIES=	x11 graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for display calibration of X11-Servers with ICC profiles

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README README.profilers
USE_XORG=	x11 xext sm xxf86vm
USES=		gmake

DEFINES=	-DXCALIB_VERSION=\"${PORTVERSION}\" -DUNIX
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib -lm -lX11 -lXxf86vm -lXext
CFLAGS+=	-I./icclib -I${LOCALBASE}/include -I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.icc ${EXAMPLESDIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
