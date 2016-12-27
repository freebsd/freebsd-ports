# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	xcalib
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	SF/openicc/xcalib/xcalib%200.9/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Program for X11 display calibration with ICC profiles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bz2
USE_XORG=	sm x11 xext xrandr xxf86vm

PORTDOCS=	README README.profilers
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' -e 's|0644|0555|g'\
	    -e 's|CFLAGS =|CFLAGS ?=|g' -e 's|/usr/X11R6|${LOCALBASE}|g' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|if(i=0)|else|g' ${WRKSRC}/xcalib.c

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.icc ${WRKSRC}/*.icm \
	    ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
