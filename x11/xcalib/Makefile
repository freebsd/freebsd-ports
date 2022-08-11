PORTNAME=	xcalib
PORTVERSION=	0.10
PORTREVISION=	0
CATEGORIES=	x11 graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for X11 display calibration with ICC profiles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	OpenICC

USES=		tar:bz2 xorg
USE_XORG=	x11 xext xrandr xxf86vm

PORTDOCS=	README.md README.profilers
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' -e 's|0644|0555|g'\
	    -e 's|CFLAGS =|CFLAGS ?=|g' -e 's|/usr/X11R6|${LOCALBASE}|g' \
	    ${WRKSRC}/Makefile

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
