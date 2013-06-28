# Created by: Alexander Matey <matey@cis.ohio-state.edu>
# $FreeBSD$

PORTNAME=	xxkb
PORTVERSION=	1.11
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	alexander.pohoyda@gmx.net
COMMENT=	XKB keyboard layout indicator and switcher

LICENSE=	ART10

USES=		iconv imake
USE_XORG=	xpm
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		${PORTNAME}.1
PORTDOCS=	README CHANGES.ru README.ru

OPTIONS_DEFINE=	LIBRSVG2 DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBRSVG2}
LIB_DEPENDS=	rsvg-2:${PORTSDIR}/graphics/librsvg2
XMKMF=		xmkmf -a -DWITH_SVG_SUPPORT
.endif

post-build:
# Convert Russian language docs from archaic KOI8-R to modern UTF-8
.for f in CHANGES README
	iconv -f koi8-r -t utf-8 ${WRKSRC}/${f}.koi8 > ${WRKSRC}/${f}.ru
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
