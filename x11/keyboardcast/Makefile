# New ports collection makefile for:   keyboardcast
# Date created:        12 jaan 2010
# Whom:                eimar.koort
#
# $FreeBSD$
#

PORTNAME=	keyboardcast
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://desrt.mcmaster.ca/code/keyboardcast/

MAINTAINER=	eimar.koort@gmail.com
COMMENT=	Broadcast keystrokes to multiple X windows for Gnome2

USE_XORG=	xmu
USE_GNOME=	libwnck libglade2 gtk20
USE_PKGCONFIG=	yes
INSTALLS_ICONS=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
