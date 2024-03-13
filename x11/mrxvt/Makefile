PORTNAME=	mrxvt
DISTVERSION=	0.5.4
CATEGORIES=	x11
MASTER_SITES=	SF/materm/mrxvt%20source/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tabbed version of rxvt
WWW=		https://materm.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		shebangfix xorg
USE_XORG=	ice x11 sm xpm xrender

SHEBANG_FILES=	${WRKSRC}/share/scripts/mrxvtset.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-utempter --disable-lastlog

CFLAGS+=		-fcommon

DESKTOP_ENTRIES=	"mrxvt" "mrxvt terminal emulator" \
			"${PREFIX}/share/pixmaps/mrxvt.png" \
			"mrxvt" "Utility;TerminalEmulator;" \
			false
SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	XFT BACKGROUND JPEG PNG TRANSPARENCY SWAPSCREEN JAPANESE 24BITS \
		MENUBAR TEXTSHADOW FRILLS DOCS EXAMPLES
OPTIONS_DEFAULT=	BACKGROUND JPEG PNG TRANSPARENCY SWAPSCREEN 24BITS \
			MENUBAR XFT JAPANESE FRILLS TEXTSHADOW

24BITS_DESC=		Prefer 24 bits color
BACKGROUND_DESC=	Background images
FRILLS_DESC=		Internal borders and smart resizing
JAPANESE_DESC=		Support for Japanese language
MENUBAR_DESC=		Menubar
SWAPSCREEN_DESC=	Swapscreen
TEXTSHADOW_DESC=	Text shadow
TRANSPARENCY_DESC=	Transparent background

24BITS_CONFIGURE_ON=	--enable-24bits
BACKGROUND_CONFIGURE_OFF=	--disable-xpm
FRILLS_CONFIGURE_ON=	--enable-frills
JAPANESE_CONFIGURE_ON=	--enable-xim --enable-cjk --with-encoding=eucj
MENUBAR_CONFIGURE_ON=	--enable-menubar
SWAPSCREEN_CONFIGURE_OFF=	--disable-swapscreen
TEXTSHADOW_CONFIGURE_ON=	--enable-text-shadow
TRANSPARENCY_CONFIGURE_OFF=	--disable-transparency
XFT_USE=		XORG=xft
XFT_CONFIGURE_ON=	--enable-xft

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT} && ${PORT_OPTIONS:MJAPANESE}
USES+=		iconv
.endif

.if ! ${PORT_OPTIONS:MJPEG} || ! ${PORT_OPTIONS:MBACKGROUND}
CONFIGURE_ARGS+=	--disable-jpeg
.else
USES+=		jpeg
.endif

.if ! ${PORT_OPTIONS:MPNG} || ! ${PORT_OPTIONS:MBACKGROUND}
CONFIGURE_ARGS+=	--disable-png
.else
LIB_DEPENDS+=	libpng.so:graphics/png
.endif

## Rarely used options, not in the main menu
# How many lines to save in the scroll buffer
.if defined(SAVE_LINES)
CONFIGURE_ARGS+=	--with-save-lines=${SAVE_LINES:M[0-9]*}
.endif

# Maximal number of terminals
.if defined(MAX_TERMINALS)
CONFIGURE_ARGS+=	--with-max-term=${MAX_TERMINALS:M[0-9]*}
.endif

# Maximal number of profiles
.if defined(MAX_PROFILES)
CONFIGURE_ARGS+=	--with-max-profiles=${MAX_PROFILES:M[0-9]*}
.endif

# Extra height of active tab as a percentage of the font height
.if defined(EXTRA_ATAB_HEIGHT)
CONFIGURE_ARGS+=	--with-atab-extra=${EXTRA_ATAB_HEIGHT:M[0-9]*}
.endif

# The radius of tab corners as a percentage of the font X offset
.if defined(TAB_RADIUS)
CONFIGURE_ARGS+=	--with-tab-radius=${TAB_RADIUS:M[0-9]*}
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=no
.else
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mrxvt ${STAGEDIR}${PREFIX}/bin
	@for pixmap in ${WRKSRC}/share/pixmaps/* ; \
	do ${INSTALL_DATA} $$pixmap ${STAGEDIR}${PREFIX}/share/pixmaps/ ; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mrxvt
	${INSTALL_DATA} ${WRKSRC}/share/mrxvtrc ${STAGEDIR}${PREFIX}/etc/mrxvt/mrxvtrc.sample
	${INSTALL_DATA} ${WRKSRC}/share/default.menu ${STAGEDIR}${PREFIX}/etc/mrxvt/default.menu.sample
	${INSTALL_DATA} ${WRKSRC}/share/submenus.menu ${STAGEDIR}${PREFIX}/etc/mrxvt/submenus.menu.sample
	${INSTALL_MAN} ${WRKSRC}/doc/mrxvt.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/share/scripts/mrxvtset.pl ${STAGEDIR}${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/share/scripts/settitle.c ${STAGEDIR}${EXAMPLESDIR}/scripts
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.bz2 ${STAGEDIR}${DOCSDIR}
	${BZIP2_CMD} -d ${STAGEDIR}${DOCSDIR}/*.bz2

.include <bsd.port.post.mk>
