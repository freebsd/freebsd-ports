# New ports collection makefile for:	fvwm-crystal
# Date created:				11 December 2007
# Whom:					Giacomo Mariani
#
# $FreeBSD$
#

PORTNAME=	fvwm-crystal
PORTVERSION=	3.0.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.gna.org/fvwm-crystal/${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Easy, eye-candy, light and powerful virtual wm for X

RUN_DEPENDS=	fvwm>=2.5:${PORTSDIR}/x11-wm/fvwm2-devel \
		bash:${PORTSDIR}/shells/bash

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
MAKE_ENV=	prefix="${PREFIX}" addondir="${DOCSDIR}/addons"

OPTIONS=	ROX "Rox-filer support" on \
		IMAGEMAGICK "Window thumbnails and screenshots support" on \
		XSCREENSAVER "Desktop screensaver support" on \
		TRAYER "Tray/notification area support" on \
		SUDO "Running text-based applications as superuser" on \
		HSETROOT "Set the desktop wallpaper" on \
		CMUS "A music playera" off

.include <bsd.port.pre.mk>

.if defined(WITH_ROX)
RUN_DEPENDS+=	rox:${PORTSDIR}/x11-fm/rox-filer
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	display:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_XSCREENSAVER)
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif

.if defined(WITH_TRAYER)
RUN_DEPENDS+=	trayer:${PORTSDIR}/x11/trayer
.endif

.if defined(WITH_SUDO)
RUN_DEPENDS+=	sudo:${PORTSDIR}/security/sudo
.endif

.if defined(WITH_HSETROOT)
RUN_DEPENDS+=	hsetroot:${PORTSDIR}/graphics/hsetroot
.endif

.if defined(WITH_CMUS)
RUN_DEPENDS+=	cmus:${PORTSDIR}/audio/cmus
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|cp -r -d|cp -r|; s|cp -d|cp|' \
		${WRKSRC}/${MAKEFILE}
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^install: uninstall|& install-doc|' \
		${WRKSRC}/${MAKEFILE}
.endif

scrivi:
	${ECHO_CMD} ${LOCALBASE}
	${ECHO_CMD} ${PREFIX}

.include <bsd.port.post.mk>
