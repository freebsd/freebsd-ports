# Created by: Giacomo Mariani <giacomomariani@yahoo.it>
# $FreeBSD$

PORTNAME=	fvwm-crystal
PORTVERSION=	3.0.6
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.gna.org/fvwm-crystal/${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Easy, eye-candy, light, and powerful window manager for X11

RUN_DEPENDS=	fvwm>=2.5:x11-wm/fvwm2 \
		bash:shells/bash

USES=		gettext gmake python shebangfix
SHEBANG_FILES=	addons/* bin/* fvwm/scripts/speed_value
MAKE_ENV=	prefix="${PREFIX}" addondir="${DOCSDIR}/addons"
PORTDOCS=	*
INSTALL_TARGET=	install
NO_ARCH=	yes

OPTIONS_DEFINE=	ROX IMAGEMAGICK XSCREENSAVER TRAYER SUDO HSETROOT CMUS DOCS
OPTIONS_DEFAULT=	ROX IMAGEMAGICK XSCREENSAVER TRAYER SUDO HSETROOT

ROX_DESC=		Rox-filer file manager support
IMAGEMAGICK_DESC=	Window thumbnails and screenshots support
XSCREENSAVER_DESC=	Desktop screensaver support
TRAYER_DESC=		Tray (notification area) support
SUDO_DESC=		Run text-based applications as superuser
HSETROOT_DESC=		Allow to set desktop wallpaper
CMUS_DESC=		Play music via audio/cmus player
MROX_RUN_DEPENDS=	rox:x11-fm/rox-filer
IMAGEMAGICK_RUN_DEPENDS=	display:graphics/ImageMagick
XSCREENSAVER_RUN_DEPENDS=	xscreensaver:x11/xscreensaver
TRAYER_RUN_DEPENDS=	trayer:x11/trayer
SUDO_RUN_DEPENDS=	sudo:security/sudo
SETROOT_RUN_DEPENDS=	hsetroot:graphics/hsetroot
CMUS_RUN_DEPENDS=	cmus:audio/cmus
DOCS_INSTALL_TARGET=	install-doc

post-extract:
	@cd ${WRKSRC} && ${FIND} . -depth -type d -name .svn \
		-exec ${RM} -rf {} \;

post-patch:
	@${REINPLACE_CMD} -e 's|cp -r -d|cp -r|; s|cp -d|cp|' \
		${WRKSRC}/${MAKEFILE}
scrivi:
	${ECHO_CMD} ${LOCALBASE}
	${ECHO_CMD} ${PREFIX}

.include <bsd.port.mk>
