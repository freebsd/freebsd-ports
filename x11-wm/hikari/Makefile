# $FreeBSD$

PORTNAME=	hikari
DISTVERSION=	0.1.2
CATEGORIES=	x11-wm
MASTER_SITES=	https://acmelabs.space/~raichoo/

MAINTAINER=	alex@xanderio.de
COMMENT=	Stacking window manager with tiling capabilities

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-ewmh.so:x11/xcb-util-wm

USES=	localbase:ldflags
USE_XORG=	xcb x11

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/hikari \
		man/man1/hikari.1.gz
PORTDATA=	config.def.h
PORTDOCS=	README.md

.if defined(WITH_DEBUG)
ALL_TARGET=	debug
.else
ALL_TARGET=	hikari
.endif

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG} "You can build hikari with your own config.h using the HIKARI_CONF knob:"
	@${ECHO_MSG} "make HIKARI_CONF=/path/to/hikari/config.h install clean"

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
