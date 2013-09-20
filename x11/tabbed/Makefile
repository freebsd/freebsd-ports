# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	tabbed
PORTVERSION=	0.3
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	winstonw@lavabit.com
COMMENT=	Simple generic tabbed fronted to xembed aware applications

LICENSE=	MIT

USE_XORG=	x11

MAN1=		tabbed.1
PLIST_FILES=	bin/tabbed
PORTDOCS=	LICENSE README

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG} "You can build tabbed with your own config.h using the TABBED_CONF knob:"
	@${ECHO_MSG} "make TABBED_CONF=/path/to/tabbed/config.h install clean"

post-extract:
.if defined(TABBED_CONF)
	@${ECHO_MSG} "creating config.h from ${TABBED_CONF}"
	@${CP} ${TABBED_CONF} ${WRKSRC}/config.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
