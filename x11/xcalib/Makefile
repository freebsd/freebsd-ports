# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	xcalib
PORTVERSION=	0.8
CATEGORIES=	x11 graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for display calibration of X11-Servers with ICC profiles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_XORG=	x11 xext sm xxf86vm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README README.profilers
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

DEFINES=	-DXCALIB_VERSION=\"${PORTVERSION}\" -DUNIX
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib -lm -lX11 -lXxf86vm -lXext
CFLAGS+=	-I./icclib -I${LOCALBASE}/include -I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.icc ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
