# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	jwm
PORTVERSION=	2.3.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://joewing.net/programs/jwm/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Window Manager

LICENSE=	GPLv2

USES=		iconv pkgconfig tar:xz
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		CAIRO DEBUG FRIBIDI JPEG NLS PNG SVG XEXT XFT \
			XINERAMA XMU XPM XRENDER
OPTIONS_DEFAULT=	JPEG NLS PNG FRIBIDI XEXT XFT XINERAMA XMU XPM XRENDER
OPTIONS_SUB=		yes

CAIRO_USE=		GNOME=cairo
CAIRO_CONFIGURE_ENABLE=	cairo
DEBUG_CONFIGURE_ENABLE=	debug
FRIBIDI_DESC=		Unicode Bidirectional Algorithm support
FRIBIDI_LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=fribidi
JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ENABLE=	png
SVG_USE=		GNOME=librsvg2
SVG_CONFIGURE_ENABLE=	rsvg
XEXT_DESC=		X11 Shape Extension support
XEXT_USE=		XORG=xext
XEXT_CONFIGURE_ENABLE=	shape
XFT_USE=		XORG=xft
XFT_CONFIGURE_ENABLE=	xft
XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_ENABLE=xinerama
XMU_DESC=		X11 Miscellaneous Utilities support
XMU_USE=		XORG=xmu
XMU_CONFIGURE_ENABLE=	xmu
XPM_USE=		XORG=xpm
XPM_CONFIGURE_ENABLE=	xpm
XRENDER_DESC=		X11 Render Extension support
XRENDER_USE=		XORG=xrender
XRENDER_CONFIGURE_ENABLE=xrender

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT} && empty(PORT_OPTIONS:MXRENDER)
IGNORE=		the XFT support requires XRENDER
.endif

.if ${PORT_OPTIONS:MXMU} && empty(PORT_OPTIONS:MXEXT)
IGNORE=		the XMU support requires XEXT
.endif

.if ${PORT_OPTIONS:MXPM} && empty(PORT_OPTIONS:MXEXT)
IGNORE=		the XPM support requires XEXT
.endif

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
