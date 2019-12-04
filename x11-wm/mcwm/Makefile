# Created by: Jakub Lach <jakub_lach@mailplus.pl>
# $FreeBSD$

PORTNAME=	mcwm
PORTVERSION=	20130209
CATEGORIES=	x11-wm
MASTER_SITES=	http://hack.org/mc/hacks/mcwm/

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Small window manager inspired by CTWM, evilwm, and tinywm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm

USES=		tar:bzip2 xorg
USE_XORG=	xcb

PLIST_FILES=	bin/mcwm bin/hidden man/man1/mcwm.1.gz man/man1/hidden.1.gz
PORTDOCS=	README NEWS

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG} "You can build mcwm with your own config.h using the MCWM_CONF knob:"
	@${ECHO_MSG} "make MCWM_CONF=/path/to/mcwm/config.h install clean"

post-extract:
.if defined(MCWM_CONF)
	@${ECHO_MSG} "creating config.h from ${MCWM_CONF}"
	@${CP} ${MCWM_CONF} ${WRKSRC}/config.h
.endif
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_PROGRAM} ${WRKSRC}/hidden ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hidden.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/hidden.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
