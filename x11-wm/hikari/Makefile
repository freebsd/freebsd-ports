# $FreeBSD$

PORTNAME=	hikari
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://acmelabs.space/~raichoo/

MAINTAINER=	alex@xanderio.de
COMMENT=	Stacking window manager with tiling capabilities

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		compiler:c11 localbase:ldflags xorg
USE_XORG=	x11 xcb

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

SUB_FILES=	hikari.desktop
SUB_LIST=	COMMENT="${COMMENT}"
PLIST_FILES=	bin/hikari \
		man/man1/hikari.1.gz \
		share/xsessions/hikari.desktop
PORTDATA=	config.def.h
PORTDOCS=	README.md

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ALL_TARGET=	debug
.else
ALL_TARGET=	hikari
.endif

pre-everything::
	@${ECHO_MSG} "You can build hikari with your own config.h using the HIKARI_CONF knob:"
	@${ECHO_MSG} "make HIKARI_CONF=/path/to/hikari/config.h install clean"
	@${ECHO_MSG} "Note: Pre-${PORTVERSION} config.h files may not work."

post-patch:
.if defined(HIKARI_CONF)
	@${ECHO_MSG} "Creating config.h from ${HIKARI_CONF}"
	@${LN} -sf ${HIKARI_CONF} ${WRKSRC}/config.h
.else
	@${LN} -sf ${WRKSRC}/config.def.h ${WRKSRC}/config.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hikari ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/hikari.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDATA} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/hikari.desktop ${STAGEDIR}${PREFIX}/share/xsessions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
