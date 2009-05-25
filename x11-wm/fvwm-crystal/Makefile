# New ports collection makefile for:	fvwm-crystal
# Date created:				11 December 2007
# Whom:					Giacomo Mariani
#
# $FreeBSD$
#

PORTNAME=	fvwm-crystal
PORTVERSION=	3.0.6
PORTREVISION=	1
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
PORTDOCS=*

MAN1=	ApplicationDatabase.1 CrystalRoxHOWTO.1 FVWMCrystalFAQ.1 \
	KeyboardBindings.1 MouseBindings.1 Tips.1

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

post-extract:
	@cd ${WRKSRC} && ${FIND} . -depth -type d -name .svn -exec ${RM} -rf {} \;

.if !defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile_NODOC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|cp -r -d|cp -r|; s|cp -d|cp|' \
		${WRKSRC}/${MAKEFILE}
.for i in addons/* bin/* fvwm/scripts/speed_value
	@${REINPLACE_CMD} -e 's|/bin/bash|${PREFIX}/bin/bash|g' ${WRKSRC}/${i}
	@${FIND} ${WRKSRC} -name '*.bak' -delete
.endfor

scrivi:
	${ECHO_CMD} ${LOCALBASE}
	${ECHO_CMD} ${PREFIX}

.include <bsd.port.post.mk>
