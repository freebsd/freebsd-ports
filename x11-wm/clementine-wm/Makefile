# Created by: trevor
# $FreeBSD$

PORTNAME=	clementine
PORTVERSION=	0.0.7
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/Source/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager based on aewm with title bars, iconization, and styles

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	xv:graphics/xv \
		rxvt:x11/rxvt

USES=		gmake
USE_XORG=	x11

PORTDOCS=	HISTORY LICENSE
PLIST_FILES=	bin/clementine \
		%%DATADIR%%/look-black \
		%%DATADIR%%/look-black2 \
		%%DATADIR%%/look-blue \
		%%DATADIR%%/look-celadon \
		%%DATADIR%%/look-grey \
		%%DATADIR%%/look-taupe \
		%%DATADIR%%/look-turq \
		%%DATADIR%%/look-xemacs \
		%%DATADIR%%/keys

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}| ; \
		 s|$$(CC)|$$(CXX)| ; \
		 s|$$(CFLAGS)|$$(CXXFLAGS)| ; \
		 s|$$(DEFINES)||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|./clementine|${PREFIX}/bin/clementine|' \
		${WRKSRC}/windowmanager.cpp

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} clementine ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in look-* keys
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DATADIR})
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
