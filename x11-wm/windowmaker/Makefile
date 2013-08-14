# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	windowmaker
PORTVERSION=	0.95.4
PORTREVISION=	1
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GNUstep-compliant NeXTstep window manager clone

LICENSE=	GPLv2

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		jbig:${PORTSDIR}/graphics/jbigkit \
		tiff:${PORTSDIR}/graphics/tiff \
		wraster:${PORTSDIR}/x11-wm/libwraster
RUN_DEPENDS=	${LOCALBASE}/share/WindowMaker/Themes/LeetWM.themed/style:${PORTSDIR}/graphics/wmicons

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_XORG=	xft xinerama xmu xpm
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama --enable-usermenu \
		--with-x
CPPFLAGS+=	-DPREFIX=\\\"${PREFIX}\\\" -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PORTDOCS=	AUTHORS BUGFORM BUGS ChangeLog FAQ FAQ.I18N INSTALL \
		INSTALL-WMAKER NEWS README README.definable-cursor TODO

OPTIONS_DEFINE=	DOCS NLS XRANDR

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 && ${OSVERSION} < 800000
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif

.if ${OSVERSION} < 800000
CPPFLAGS+=	-DHAVE_SYS_SELECT_H
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LINGUAS=	be bg bs ca cs da de el es et fi fr gl hr hu hy it \
		ja ko ms nl no pl pt ro ru sk sv tr zh_CN zh_TW
CONFIGURE_ENV+=	LINGUAS="${LINGUAS}"
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=--disable-locale
PLIST_SUB=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MXRANDR}
USE_XORG+=	xrandr
CONFIGURE_ARGS+=--enable-xrandr
.endif

MANLANG=	"" cs sk ru
MAN1_EN=	geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x get-wings-flags.1 \
		get-wutil-flags.1 wdread.1 WindowMaker.1x wmagnify.1x \
		wmgenmenu.1 wmmenugen.1 WPrefs.1x
MAN8_EN=	upgrade-windowmaker-defaults.8
MAN1_CS=	geticonset.1x setstyle.1x wxpaste.1x getstyle.1x wdwrite.1x \
		wmsetbg.1x seticons.1x wmaker.1x wxcopy.1x
MAN1_SK=	geticonset.1x setstyle.1x wxpaste.1x getstyle.1x wdwrite.1x \
		wmsetbg.1x seticons.1x wmaker.1x wxcopy.1x
MAN1_RU=	geticonset.1x setstyle.1x wxpaste.1x getstyle.1x wdwrite.1x \
		wmsetbg.1x seticons.1x wmaker.1x wxcopy.1x

post-install:
	@${MKDIR} \
		${PREFIX}/GNUstep/Applications/WPrefs.app/xpm \
		${PREFIX}/share/WindowMaker/Sounds
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
