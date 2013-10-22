# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	mrxvt-devel
PORTVERSION=	0.5.4
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	SF/materm/mrxvt%20source/${PORTVERSION}
DISTNAME=	mrxvt-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Development version of mrxvt

CONFLICTS=	mrxvt-0.4.*
USE_XORG=	x11
GNU_CONFIGURE=	yes

MAN1=		mrxvt.1

SUB_FILES+=	pkg-message

DESKTOP_ENTRIES=	"mrxvt" "mrxvt terminal emulator" \
			"${PREFIX}/share/pixmaps/mrxvt.png" \
			"mrxvt" "Utility;TerminalEmulator;" \
			false

OPTIONS_DEFINE=	XFT BACKGROUND JPEG PNG TRANSPARENCY SWAPSCREEN JAPANESE 24BITS \
		MENUBAR TEXTSHADOW FRILLS DOCS EXAMPLES
OPTIONS_DEFAULT=	BACKGROUND JPEG PNG TRANSPARENCY SWAPSCREEN 24BITS MENUBAR
BACKGROUND_DESC=	Background images
TRANSPARENCY_DESC=	transparency
SWAPSCREEN_DESC=	Swapscreen
JAPANESE_DESC=		Support for Japanese language
24BITS_DESC=		Prefer 24 bits color
MENUBAR_DESC=		Menubar
TEXTSHADOW_DESC=	Text shadow
FRILLS_DESC=		Internal borders and smart resizing

NO_STAGE=	yes
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--enable-utempter
.if ${OSVERSION} >= 900004
CONFIGURE_ARGS+=	--disable-lastlog
.else
LIB_DEPENDS+=		utempter.0:${PORTSDIR}/sysutils/libutempter
.endif

.if ${PORT_OPTIONS:MJAPANESE}
CONFIGURE_ARGS+=	--enable-xim --enable-cjk --with-encoding=eucj
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
CONFIGURE_ARGS+=	--enable-xft
.endif

.if ${PORT_OPTIONS:M24BITS}
CONFIGURE_ARGS+=	--enable-24bits
.endif

.if ! ${PORT_OPTIONS:MBACKGROUND}
CONFIGURE_ARGS+=	--disable-xpm
.endif

.if ! ${PORT_OPTIONS:MJPEG} || ! ${PORT_OPTIONS:MBACKGROUND}
CONFIGURE_ARGS+=	--disable-jpeg
.else
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
.endif

.if ! ${PORT_OPTIONS:MPNG} || ! ${PORT_OPTIONS:MBACKGROUND}
CONFIGURE_ARGS+=	--disable-png
.else
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.endif

.if ! ${PORT_OPTIONS:MTRANSPARENCY}
CONFIGURE_ARGS+=	--disable-transparency
.endif

.if ${PORT_OPTIONS:MMENUBAR}
CONFIGURE_ARGS+=	--enable-menubar
.endif

.if ${PORT_OPTIONS:MTEXTSHADOW}
CONFIGURE_ARGS+=	--enable-text-shadow
.endif

.if ! ${PORT_OPTIONS:MSWAPSCREEN}
CONFIGURE_ARGS+=	--disable-swapscreen
.endif

.if ${PORT_OPTIONS:MFRILLS}
CONFIGURE_ARGS+=	--enable-frills
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mrxvt ${PREFIX}/bin
	@for pixmap in ${WRKSRC}/share/pixmaps/* ; \
	do ${INSTALL_DATA} $$pixmap ${PREFIX}/share/pixmaps/ ; \
	done
	${MKDIR} ${PREFIX}/etc/mrxvt
	${INSTALL_DATA} ${WRKSRC}/share/mrxvtrc ${PREFIX}/etc/mrxvt/mrxvtrc.sample
	${INSTALL_DATA} ${WRKSRC}/share/default.menu ${PREFIX}/etc/mrxvt/default.menu.sample
	${INSTALL_DATA} ${WRKSRC}/share/submenus.menu ${PREFIX}/etc/mrxvt/submenus.menu.sample
	${INSTALL_MAN} ${WRKSRC}/doc/mrxvt.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/share/scripts/mrxvtset.pl ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/share/scripts/settitle.c ${EXAMPLESDIR}/scripts
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.bz2 ${DOCSDIR}
	${BZIP2_CMD} -d ${DOCSDIR}/*.bz2
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
