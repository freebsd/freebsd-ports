# New ports collection makefile for:    xorg-protos
# Date created:				Sep 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-protos
PORTVERSION=	7.3
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org protos meta-port

USE_X_PREFIX=	yes

BUILD_DEPENDS=	${PREFIX}/include/X11/extensions/bigreqstr.h:${PORTSDIR}/x11/bigreqsproto \
		${PREFIX}/include/X11/extensions/composite.h:${PORTSDIR}/x11/compositeproto \
		${PREFIX}/include/X11/extensions/damageproto.h:${PORTSDIR}/x11/damageproto \
		${PREFIX}/include/X11/extensions/dmxproto.h:${PORTSDIR}/x11/dmxproto \
		${PREFIX}/include/X11/extensions/xfixesproto.h:${PORTSDIR}/x11/fixesproto \
		${PREFIX}/include/X11/extensions/fontcache.h:${PORTSDIR}/x11-fonts/fontcacheproto \
		${PREFIX}/include/X11/fonts/FS.h:${PORTSDIR}/x11-fonts/fontsproto \
		${PREFIX}/include/GL/glxproto.h:${PORTSDIR}/x11/glproto \
		${PREFIX}/include/X11/extensions/XIproto.h:${PORTSDIR}/x11/inputproto \
		${PREFIX}/include/X11/extensions/XKB.h:${PORTSDIR}/x11/kbproto \
		${PREFIX}/include/X11/extensions/Print.h:${PORTSDIR}/x11/printproto \
		${PREFIX}/include/X11/extensions/randr.h:${PORTSDIR}/x11/randrproto \
		${PREFIX}/include/X11/extensions/recordstr.h:${PORTSDIR}/x11/recordproto \
		${PREFIX}/include/X11/extensions/render.h:${PORTSDIR}/x11/renderproto \
		${PREFIX}/include/X11/extensions/XResproto.h:${PORTSDIR}/x11/resourceproto \
		${PREFIX}/include/X11/extensions/saver.h:${PORTSDIR}/x11/scrnsaverproto \
		${PREFIX}/include/X11/extensions/xtrapproto.h:${PORTSDIR}/x11/trapproto \
		${PREFIX}/include/X11/extensions/Xv.h:${PORTSDIR}/x11/videoproto \
		${PREFIX}/include/X11/extensions/xcmiscstr.h:${PORTSDIR}/x11/xcmiscproto \
		${PREFIX}/include/X11/extensions/MITMisc.h:${PORTSDIR}/x11/xextproto \
		${PREFIX}/include/X11/extensions/xf86bigfont.h:${PORTSDIR}/x11-fonts/xf86bigfontproto \
		${PREFIX}/include/X11/extensions/xf86dga.h:${PORTSDIR}/x11/xf86dgaproto \
		${PREFIX}/include/GL/internal/dri_interface.h:${PORTSDIR}/x11/xf86driproto \
		${PREFIX}/include/X11/extensions/xf86misc.h:${PORTSDIR}/x11/xf86miscproto \
		${PREFIX}/include/X11/extensions/xf86rush.h:${PORTSDIR}/x11/xf86rushproto \
		${PREFIX}/include/X11/extensions/xf86vmode.h:${PORTSDIR}/x11/xf86vidmodeproto \
		${PREFIX}/include/X11/extensions/panoramiXproto.h:${PORTSDIR}/x11/xineramaproto \
		${PREFIX}/include/X11/DECkeysym.h:${PORTSDIR}/x11/xproto \
		${PREFIX}/include/X11/PM/PM.h:${PORTSDIR}/x11/xproxymanagementprotocol

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/protos

.include <bsd.port.mk>
