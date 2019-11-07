# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	tabbed
PORTVERSION=	0.6
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Simple generic tabbed fronted to xembed aware applications

LICENSE=	MIT

USES=		xorg
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/tabbed \
		man/man1/tabbed.1.gz
PORTDOCS=	LICENSE README

pre-everything::
	@${ECHO_MSG} "You can build tabbed with your own config.h using the TABBED_CONF knob:"
	@${ECHO_MSG} "make TABBED_CONF=/path/to/tabbed/config.h install clean"

post-extract:
.if defined(TABBED_CONF)
	@${ECHO_MSG} "creating config.h from ${TABBED_CONF}"
	@${CP} ${TABBED_CONF} ${WRKSRC}/config.h
.endif
	@${REINPLACE_CMD} 's|-std=c99 -pedantic -Wall -O0|${CFLAGS}|' \
		${WRKSRC}/config.mk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
