# Created by: Jakub Lach <jakub_lach@mailplus.pl>
# $FreeBSD$

PORTNAME=	mcwm
PORTVERSION=	20111124
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://hack.org/mc/hacks/mcwm/

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Small window manager inspired by CTWM, evilwm, and tinywm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	xcb-util:${PORTSDIR}/x11/xcb-util \
		xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms \
		xcb-icccm:${PORTSDIR}/x11/xcb-util-wm

MAKE_JOBS_SAFE=	yes

USE_XORG=	x11 xrandr
USE_BZIP2=	yes

MAN1=		mcwm.1
PLIST_FILES=	bin/mcwm
PORTDOCS=	README NEWS

pre-everything::
		@${ECHO_MSG} "You can build mcwm with your own config.h using the MCWM_CONF knob:"
		@${ECHO_MSG} "make MCWM_CONF=/path/to/mcwm/config.h install clean"

post-extract:
.if defined(MCWM_CONF)
	@${ECHO_MSG} "creating config.h from ${MCWM_CONF}"
	@${CP} ${MCWM_CONF} ${WRKSRC}/config.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${MAN1PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
