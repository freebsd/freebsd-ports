PORTNAME=	jwm
PORTVERSION=	2.4.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/joewing/jwm/releases/download/v${PORTVERSION}/

MAINTAINER=	john.grafton@gmail.com
COMMENT=	Joe's Window Manager
WWW=		https://joewing.net/projects/jwm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libglib-2.0.so.0:devel/glib20 \
		libgobject-2.0.so.0:devel/glib20 \
		libpango-1.0.so.0:x11-toolkits/pango

USES=		iconv localbase pkgconfig tar:xz xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=		CAIRO DEBUG FRIBIDI JPEG NLS PNG SVG XEXT XFT \
			XINERAMA XMU XPM XRENDER
OPTIONS_DEFAULT=	FRIBIDI JPEG PNG XEXT XFT XINERAMA XMU XPM XRENDER
OPTIONS_SUB=		yes

FRIBIDI_DESC=		Unicode Bidirectional Algorithm support
XEXT_DESC=		X11 Shape Extension support
XMU_DESC=		X11 Miscellaneous Utilities support
XRENDER_DESC=		X11 Render Extension support

CAIRO_USES=		gnome
CAIRO_USE=		GNOME=cairo
CAIRO_CONFIGURE_ENABLE=	cairo
DEBUG_CONFIGURE_ENABLE=	debug
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=fribidi
JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png
SVG_USE=		GNOME=librsvg2
SVG_CONFIGURE_ENABLE=	rsvg
XEXT_USE=		XORG=xext
XEXT_CONFIGURE_ENABLE=	shape
XFT_IMPLIES=		XRENDER
XFT_LIB_DEPENDS=	libfreetype.so:print/freetype2
XFT_USE=		XORG=xft
XFT_CONFIGURE_ENABLE=	xft
XINERAMA_IMPLIES=	XEXT
XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_ENABLE=xinerama
XMU_IMPLIES=		XEXT
XMU_USE=		XORG=xmu
XMU_CONFIGURE_ENABLE=	xmu
XPM_IMPLIES=		XEXT
XPM_USE=		XORG=xpm
XPM_CONFIGURE_ENABLE=	xpm
XRENDER_USE=		XORG=xrender
XRENDER_CONFIGURE_ENABLE=xrender

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/example.jwmrc
	@${REINPLACE_CMD} -e \
		's|install -m 644|@INSTALL_DATA@| ; \
		 s|jwmrc$$|jwmrc.sample|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/EXE/s|install|@INSTALL_PROGRAM@| ; \
		 /strip/s|^|#|' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
