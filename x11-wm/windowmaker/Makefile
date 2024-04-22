PORTNAME=	windowmaker
PORTVERSION=	0.96.0
PORTREVISION=	2
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	https://www.windowmaker.org/pub/source/release/ \
		https://github.com/window-maker/wmaker/releases/download/wmaker-${PORTVERSION}/ LOCAL/danfe
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GNUstep-compliant NeXTstep window manager clone
WWW=		https://www.windowmaker.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libwraster.so:x11-wm/libwraster \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libexif.so:graphics/libexif
RUN_DEPENDS=	${LOCALBASE}/share/WindowMaker/Themes/LeetWM.themed/style:graphics/wmicons

USES=		cpe desktop-file-utils gmake gnome jpeg libtool localbase \
		pathfix perl5 pkgconfig shebangfix xorg
USE_CSTD=	c99
USE_GNOME=	pango
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xinerama xmu xpm xrandr xres
SHEBANG_FILES=	util/wkdemenu.pl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no \
		wm_cv_func_secure_getenv=no
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--localedir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-pango \
		--enable-xinerama \
		--enable-usermenu \
		--enable-wmreplace \
		--enable-xrandr \
		--with-x
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS BUGFORM BUGS ChangeLog FAQ INSTALL \
		INSTALL-WMAKER NEWS README README.definable-cursor \
		README.i18n TODO The-perfect-Window-Maker-patch.txt

OPTIONS_DEFINE=	IMAGEMAGICK DOCS NLS
OPTIONS_DEFAULT=	IMAGEMAGICK
OPTIONS_SUB=	yes

IMAGEMAGICK_USES=		magick
IMAGEMAGICK_CONFIGURE_OFF=	--disable-magick

NLS_USES=	gettext
NLS_CONFIGURE_ENV=	LINGUAS="*"
NLS_CONFIGURE_ENABLE=	locale

.include <bsd.port.options.mk>

post-patch-IMAGEMAGICK-on:
.if ${IMAGEMAGICK_DEFAULT} == 6
	@${REINPLACE_CMD} -e '/MagickWand\.h/s,MagickWand/,wand/,' \
	    ${WRKSRC}/configure ${WRKSRC}/wrlib/load_magick.c
.endif

post-install:
	@${MKDIR} \
	    ${STAGEDIR}${PREFIX}/GNUstep/Applications/WPrefs.app/xpm \
	    ${STAGEDIR}${PREFIX}/share/WindowMaker/Sounds

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
