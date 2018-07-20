# Created by: Jeroen Schot <schot@a-eskwadraat.nl>
# $FreeBSD$

PORTNAME=	dwm
PORTVERSION=	6.1
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Dynamic, small, fast and simple window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USE_XORG=	x11 xft

MAKE_ARGS=	CC="${CC}" PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}/man" \
		X11INC="${LOCALBASE}/include" X11LIB="${LOCALBASE}/lib"

PLIST_FILES=	bin/dwm \
		man/man1/dwm.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DMENUANDSTERM DOCS SUPERASMODKEY VOLUMECONTROL XINERAMA
OPTIONS_DEFAULT=DMENUANDSTERM XINERAMA

DMENUANDSTERM_DESC=	Install x11/dmenu and x11/st as runtime dependencies
SUPERASMODKEY_DESC=	Use Super instead of Alt for the dwm mod key
VOLUMECONTROL_DESC=	Use keys on keyboard to raise or lower volume

DMENUANDSTERM_RUN_DEPENDS=	dmenu:x11/dmenu \
				st:x11/sterm

SUPERASMODKEY_EXTRA_PATCHES=	${PATCHDIR}/superasmodkey-patch-config.def.h
VOLUMECONTROL_EXTRA_PATCHES=	${PATCHDIR}/volumecontrol-patch-config.def.h

XINERAMA_USE=	XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	XINERAMAFLAGS= XINERAMALIBS=

pre-everything::
	@${ECHO_MSG} "You can build dwm with your own config.h using the DWM_CONF knob:"
	@${ECHO_MSG} "make DWM_CONF=/path/to/dwm/config.h install clean"
	@${ECHO_MSG} "Note: Pre-${PORTVERSION} config.h-files may not work."

post-extract:
	@if [ -e "${DWM_CONF}" ]; then \
		${ECHO_MSG} "Creating symlink: config.h -> ${DWM_CONF}"; \
		${LN} -fs "${DWM_CONF}" ${WRKSRC}/config.h; \
	fi

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dwm

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
