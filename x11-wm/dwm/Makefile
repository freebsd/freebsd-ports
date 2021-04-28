# Created by: Jeroen Schot <schot@a-eskwadraat.nl>

PORTNAME=	dwm
DISTVERSION=	6.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Dynamic, small, fast and simple window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
# Kyua is not used by the upstream to test. It's only used in the port's
# do-test target.
TEST_DEPENDS=	${LOCALBASE}/libexec/atf-check:devel/kyua

USES=		xorg
USE_XORG=	x11 xft

MAKE_ARGS=	CC="${CC}" \
		FREETYPEINC="${LOCALBASE}/include/freetype2" \
		PREFIX="${PREFIX}" \
		VERSION="${PORTVERSION}" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib"

SUB_FILES=	dwm.desktop
SUB_LIST=	COMMENT="${COMMENT}"
PLIST_FILES=	bin/dwm \
		share/man/man1/dwm.1.gz \
		share/xsessions/dwm.desktop
PORTDOCS=	README

OPTIONS_DEFINE=	DMENUANDSTERM DOCS RUGAPS SUPERASMODKEY VOLUMECONTROL XINERAMA
OPTIONS_DEFAULT=DMENUANDSTERM XINERAMA

DMENUANDSTERM_DESC=	Install x11/dmenu and x11/sterm as runtime dependencies
RUGAPS_DESC=		Add resizeable runtime useless gaps
SUPERASMODKEY_DESC=	Use Super instead of Alt for the dwm mod key
VOLUMECONTROL_DESC=	Use multimedia keys to raise or lower volume

DMENUANDSTERM_RUN_DEPENDS=	dmenu:x11/dmenu \
				st:x11/sterm

RUGAPS_PATCH_SITES=		https://dwm.suckless.org/patches/ru_gaps/
RUGAPS_PATCHFILES=		dwm-ru_gaps-6.2.diff:-p1

SUPERASMODKEY_EXTRA_PATCHES=	${PATCHDIR}/superasmodkey-patch-config.def.h
VOLUMECONTROL_EXTRA_PATCHES=	${PATCHDIR}/volumecontrol-patch-config.def.h

XINERAMA_USE=	XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	XINERAMAFLAGS= XINERAMALIBS=

pre-everything::
	@${ECHO_MSG} "You can build dwm with your own config.h using the DWM_CONF knob:"
	@${ECHO_MSG} "make DWM_CONF=/path/to/dwm/config.h install clean"
	@${ECHO_MSG} "Note: Pre-${PORTVERSION} config.h-files may not work."

.if exists(${DWM_CONF})
post-extract:
	@${ECHO_MSG} "Creating symlink: config.h -> ${DWM_CONF}"
	${LN} -fs "${DWM_CONF}" ${WRKSRC}/config.h
.endif

post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|(CFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(CPPFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(LDFLAGS[[:space:]]*)= |\1+= |" \
		${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dwm
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/dwm.desktop ${STAGEDIR}${PREFIX}/share/xsessions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-test:
	${LOCALBASE}/libexec/atf-check -s exit:1 -e match:"dwm-${PORTVERSION}" \
		${STAGEDIR}${PREFIX}/bin/dwm -v

.include <bsd.port.mk>
