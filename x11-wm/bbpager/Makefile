# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	bbpager
DISTVERSION=	0.4.7
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Pager for the Blackbox window manager

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

BUILD_DEPENDS=	blackbox:x11-wm/blackbox

USES=		pathfix pkgconfig
USE_XORG=	xext sm x11 xau xcursor xi
GNU_CONFIGURE=	yes
CPPFLAGS+=	`pkg-config --cflags xft`
LDFLAGS+=	`pkg-config --libs xft`

DOCS=		AUTHORS BUGS COPYING ChangeLog INSTALL NEWS \
		README TODO
EXAMPLES=	bbpager.rc README.bbpager

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bbpager ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/data/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
