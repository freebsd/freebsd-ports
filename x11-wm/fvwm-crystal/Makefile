# Created by: Giacomo Mariani <giacomomariani@yahoo.it>
# $FreeBSD$

PORTNAME=	fvwm-crystal
PORTVERSION=	3.0.6
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.gna.org/fvwm-crystal/${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Easy, eye-candy, light, and powerful window manager for X11

RUN_DEPENDS=	fvwm>=2.5:${PORTSDIR}/x11-wm/fvwm2 \
		bash:${PORTSDIR}/shells/bash

USES=		gettext gmake
USE_PYTHON=	yes
MAKE_ENV=	prefix="${PREFIX}" addondir="${DOCSDIR}/addons"
PORTDOCS=	*

MAN1=		ApplicationDatabase.1 CrystalRoxHOWTO.1 FVWMCrystalFAQ.1 \
		KeyboardBindings.1 MouseBindings.1 Tips.1

OPTIONS_DEFINE=	ROX IMAGEMAGICK XSCREENSAVER TRAYER SUDO HSETROOT CMUS DOCS
OPTIONS_DEFAULT=	ROX IMAGEMAGICK XSCREENSAVER TRAYER SUDO HSETROOT

ROX_DESC=		Rox-filer file manager support
IMAGEMAGICK_DESC=	Window thumbnails and screenshots support
XSCREENSAVER_DESC=	Desktop screensaver support
TRAYER_DESC=		Tray (notification area) support
SUDO_DESC=		Run text-based applications as superuser
HSETROOT_DESC=		Allow to set desktop wallpaper
CMUS_DESC=		Play music via audio/cmus player

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MROX}
RUN_DEPENDS+=	rox:${PORTSDIR}/x11-fm/rox-filer
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
RUN_DEPENDS+=	display:${PORTSDIR}/graphics/ImageMagick
.endif

.if ${PORT_OPTIONS:MXSCREENSAVER}
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif

.if ${PORT_OPTIONS:MTRAYER}
RUN_DEPENDS+=	trayer:${PORTSDIR}/x11/trayer
.endif

.if ${PORT_OPTIONS:MSUDO}
RUN_DEPENDS+=	sudo:${PORTSDIR}/security/sudo
.endif

.if ${PORT_OPTIONS:MHSETROOT}
RUN_DEPENDS+=	hsetroot:${PORTSDIR}/graphics/hsetroot
.endif

.if ${PORT_OPTIONS:MCMUS}
RUN_DEPENDS+=	cmus:${PORTSDIR}/audio/cmus
.endif

post-extract:
	@cd ${WRKSRC} && ${FIND} . -depth -type d -name .svn \
		-exec ${RM} -rf {} \;

.if ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile_NODOC
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

.include <bsd.port.mk>
