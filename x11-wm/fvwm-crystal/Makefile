# Created by: Giacomo Mariani <giacomomariani@yahoo.it>
# $FreeBSD$

PORTNAME=	fvwm-crystal
PORTVERSION=	3.4.1
CATEGORIES=	x11-wm
MASTER_SITES=	https://sourceforge.net/projects/fvwm-crystal/files/${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Easy, eye-candy, light, and powerful window manager for X11

LICENSE=	GPLv3+

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	fvwm>=2.5:x11-wm/fvwm2 \
		bash:shells/bash

USES=		gettext gmake python:2.7 shebangfix

SHEBANG_FILES=	addons/* bin/* fvwm/scripts/* \
		fvwm/scripts/FvwmMPD/*.py
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
ROX_RUN_DEPENDS=	rox:x11-fm/rox-filer
IMAGEMAGICK_RUN_DEPENDS=	display:graphics/ImageMagick6
XSCREENSAVER_RUN_DEPENDS=	xscreensaver:x11/xscreensaver
TRAYER_RUN_DEPENDS=	trayer:x11/trayer
SUDO_RUN_DEPENDS=	sudo:security/sudo
HSETROOT_RUN_DEPENDS=	hsetroot:x11/hsetroot
CMUS_RUN_DEPENDS=	cmus:audio/cmus
DOCS_INSTALL_TARGET=	install-doc

post-extract:
	cd ${WRKSRC} && ${FIND} . -depth -type d -name .svn \
		-exec ${RM} -r {} \;

post-patch:
	${REINPLACE_CMD} -e 's|cp -r -d|cp -r|; s|cp -d|cp|' \
		${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|' \
		${WRKSRC}/fvwm/preferences/*
	${GZIP_CMD} ${WRKSRC}/man/*.1

scrivi:
	${ECHO_CMD} ${LOCALBASE}
	${ECHO_CMD} ${PREFIX}

.include <bsd.port.mk>
