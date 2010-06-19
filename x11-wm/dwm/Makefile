# New ports collection makefile for:   dwm
# Date created:                July 24, 2006
# Whom:                        Jeroen Schot <schot@a-eskwadraat.nl>
#
# $FreeBSD$
#

PORTNAME=	dwm
PORTVERSION=	5.8.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	A dynamic, small, fast and simple window manager

RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu

USE_XORG=	x11 xinerama

MAN1=		dwm.1
PLIST_FILES=	bin/dwm
PORTDOCS=	LICENSE README

pre-everything::
	@${ECHO_MSG} "You can build dwm with your own config.h using the DWM_CONF knob:"
	@${ECHO_MSG} "make DWM_CONF=/path/to/dwm/config.h install clean"
	@${ECHO_MSG} "Note: Pre-5.6 config.h-files no longer work."

post-extract:
.if defined(DWM_CONF)
	@${ECHO_MSG} "creating config.h from ${DWM_CONF}"
	@${CP} ${DWM_CONF} ${WRKSRC}/config.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
