# New ports collection makefile for:   dwm
# Date created:                July 24, 2006
# Whom:                        Jeroen Schot <schot@a-eskwadraat.nl>
#
# $FreeBSD$
#

PORTNAME=	dwm
PORTVERSION=	3.9
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.suckless.org/download/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	A dynamic, small, fast and simple window manager

USE_XLIB=	yes

MAN1=		dwm.1
PLIST_FILES=	bin/dwm

.if defined(DWM_CONF)
PKGNAMESUFFIX=-custom
.endif

pre-everything::
	@${ECHO_MSG} "You can build dwm with your own config.h using the DWM_CONF knob:"
	@${ECHO_MSG} "make DWM_CONF=/path/to/dwm/config.h install clean"
	@${ECHO_MSG} "Note: Pre-3.7 config.h-files no longer work."

post-extract:
.if defined(DWM_CONF)
	@${ECHO_MSG} "creating config.h from ${DWM_CONF}"
	@${CP} ${DWM_CONF} ${WRKSRC}/config.h
.endif

.include <bsd.port.mk>
