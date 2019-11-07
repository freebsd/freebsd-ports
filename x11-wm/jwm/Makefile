# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	jwm
PORTVERSION=	2.3.7
CATEGORIES=	x11-wm
MASTER_SITES=	http://joewing.net/projects/jwm/releases/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Joe's Window Manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		iconv localbase pkgconfig tar:xz xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CAIRO DEBUG FRIBIDI JPEG NLS PNG SVG XEXT XFT \
			XINERAMA XMU XPM XRENDER
OPTIONS_DEFAULT=	FRIBIDI JPEG PNG XEXT XFT XINERAMA XMU XPM XRENDER
OPTIONS_SUB=		yes

CAIRO_USES=		gnome
CAIRO_USE=		GNOME=cairo
CAIRO_CONFIGURE_ENABLE=	cairo
DEBUG_CONFIGURE_ENABLE=	debug
FRIBIDI_DESC=		Unicode Bidirectional Algorithm support
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
XEXT_DESC=		X11 Shape Extension support
XEXT_USE=		XORG=xext
XEXT_CONFIGURE_ENABLE=	shape
XFT_USE=		XORG=xft
XFT_CONFIGURE_ENABLE=	xft
XFT_IMPLIES=		XRENDER
XFT_LIB_DEPENDS=	libfreetype.so:print/freetype2
XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_ENABLE=xinerama
XINERAMA_IMPLIES=	XEXT
XMU_DESC=		X11 Miscellaneous Utilities support
XMU_USE=		XORG=xmu
XMU_CONFIGURE_ENABLE=	xmu
XMU_IMPLIES=		XEXT
XPM_USE=		XORG=xpm
XPM_CONFIGURE_ENABLE=	xpm
XPM_IMPLIES=		XEXT
XRENDER_DESC=		X11 Render Extension support
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
