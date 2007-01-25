# New ports collection makefile for:   dwm
# Date created:                July 24, 2006
# Whom:                        Jeroen Schot <schot@a-eskwadraat.nl>
#
# $FreeBSD$
#

PORTNAME=	dwm
PORTVERSION=	3.2.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://suckless.org/download/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	A dynamic, small, fast and simple window manager

USE_XLIB=	yes

pre-everything::
		@${ECHO} ==================================================================
		@${ECHO} You may build dwm with your own config.h, just use DWM_CONF knob:
		@${ECHO} make DWM_CONF=/path/to/dwm/config.h install clean
		@${ECHO} ==================================================================

.if defined(DWM_CONF)
	@${CP} {$DWM_CONF} ${WRKSRC}/config.h
.endif

MAN1=		dwm.1
PLIST_FILES=	bin/dwm

.include <bsd.port.mk>
