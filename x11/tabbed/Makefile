PORTNAME=	tabbed
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Tabbed frontend to Xembed-aware applications
WWW=		https://tools.suckless.org/tabbed

LICENSE=	MIT

USES=		xorg
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/tabbed \
		share/man/man1/tabbed.1.gz
PORTDOCS=	LICENSE README
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}"

pre-everything::
	@${ECHO_MSG} "You can build tabbed with your own config.h using the TABBED_CONF knob:"
	@${ECHO_MSG} "make TABBED_CONF=/path/to/tabbed/config.h install clean"

post-extract:
.if defined(TABBED_CONF)
	@${ECHO_MSG} "creating config.h from ${TABBED_CONF}"
	@${CP} ${TABBED_CONF} ${WRKSRC}/config.h
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
