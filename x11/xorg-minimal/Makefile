# New ports collection makefile for: xorg-minimal
# Date created: 19 Jun 2008
# Whom: Eitan Adler
#
# $FreeBSD$
#

PORTNAME=	xorg
PORTVERSION=	7.4
PORTREVISION=	2
CATEGORIES=	x11 x11-servers
MASTER_SITES=	# none
PKGNAMESUFFIX=	-minimal
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	X.Org minimal distribution metaport

NO_BUILD=	yes

RUN_DEPENDS+=	${LOCALBASE}/bin/Xorg:${PORTSDIR}/x11-servers/xorg-server \
		${LOCALBASE}/lib/xorg/modules/drivers/vesa_drv.so:${PORTSDIR}/x11-drivers/xf86-video-vesa \
		${LOCALBASE}/lib/xorg/modules/input/mouse_drv.so:${PORTSDIR}/x11-drivers/xf86-input-mouse \
		${LOCALBASE}/lib/xorg/modules/input/kbd_drv.so:${PORTSDIR}/x11-drivers/xf86-input-keyboard \
		xinit:${PORTSDIR}/x11/xinit \
		xauth:${PORTSDIR}/x11/xauth \
		${LOCALBASE}/lib/X11/fonts/misc/fonts.alias:${PORTSDIR}/x11-fonts/font-alias \
		${LOCALBASE}/lib/X11/fonts/misc/cursor.pcf.gz:${PORTSDIR}/x11-fonts/font-cursor-misc \
		${LOCALBASE}/lib/X11/fonts/misc/10x20.pcf.gz:${PORTSDIR}/x11-fonts/font-misc-misc

do-install:

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"
	@${ECHO_MSG} "This port does not ensure things are upgraded; use portmaster if you want to"
	@${ECHO_MSG} "upgrade X.Org."

.include <bsd.port.mk>
