# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	windowmaker
PORTVERSION=	0.95.7
PORTREVISION=	5
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/source/release/
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GNUstep-compliant NeXTstep window manager clone

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libMagickWand-6.so:graphics/ImageMagick \
		libwraster.so.5:x11-wm/libwraster
RUN_DEPENDS=	${LOCALBASE}/share/WindowMaker/Themes/LeetWM.themed/style:graphics/wmicons

USES=		jpeg libtool shebangfix pathfix perl5 pkgconfig
USE_LDCONFIG=	yes
USE_XORG=	xft xinerama xmu xpm
SHEBANG_FILES=	util/wkdemenu.pl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no \
		wm_cv_func_secure_getenv=no
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--localedir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama \
		--enable-usermenu \
		--enable-wmreplace \
		--with-x
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
PORTDOCS=	AUTHORS BUGFORM BUGS ChangeLog FAQ INSTALL \
		INSTALL-WMAKER NEWS README README.definable-cursor \
		README.i18n TODO The-perfect-Window-Maker-patch.txt

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENV=	LINGUAS="*"
NLS_CONFIGURE_ENABLE=	locale

post-install:
	@${MKDIR} \
	    ${STAGEDIR}${PREFIX}/GNUstep/Applications/WPrefs.app/xpm \
	    ${STAGEDIR}${PREFIX}/share/WindowMaker/Sounds

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
