# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	jwm
PORTVERSION=	2.1.0
CATEGORIES=	x11-wm
MASTER_SITES=	SF \
		http://joewing.net/programs/jwm/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Window Manager

LICENSE=	GPLv2

OPTIONS_DEFINE=	FRIBIDI XEXT XFT XINERAMA XMU XPM XRENDER JPEG PNG DEBUG
OPTIONS_DEFAULT=FRIBIDI XEXT XFT XINERAMA XMU XPM XRENDER JPEG PNG
FRIBIDI_DESC=	Unicode Bidirectional Algorithm support
XEXT_DESC=	X11 Shape Extension support
XMU_DESC=	X11 Miscellaneous Utilities support
XRENDER_DESC=	X11 Render Extension support

USE_BZIP2=	yes
USES=		pkgconfig
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	libfribidi.so:${PORTSDIR}/converters/fribidi
.else
CONFIGURE_ARGS+=	--disable-fribidi
.endif

.if ${PORT_OPTIONS:MXEXT}
USE_XORG+=	xext
.else
CONFIGURE_ARGS+=	--disable-shape
.endif

.if ${PORT_OPTIONS:MXFT}
.if empty(PORT_OPTIONS:MXRENDER)
IGNORE=	XFT support requires XRENDER
.endif
USE_XORG+=	xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if ${PORT_OPTIONS:MXMU}
.if empty(PORT_OPTIONS:MXEXT)
IGNORE=	XMU support requires XEXT
.endif
USE_XORG+=	xmu
.else
CONFIGURE_ARGS+=	--disable-xmu
.endif

.if ${PORT_OPTIONS:MXPM}
.if empty(PORT_OPTIONS:MXEXT)
IGNORE=	XPM support requires XEXT
.endif
USE_XORG+=	xpm
.else
CONFIGURE_ARGS+=	--disable-xpm
.endif

.if ${PORT_OPTIONS:MXRENDER}
USE_XORG+=	xrender
.else
CONFIGURE_ARGS+=	--disable-xrender
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=   libjpeg.so:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=        --disable-jpeg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=        --disable-png
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=        --enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/example.jwmrc
	@${REINPLACE_CMD} -e 's|fribidi_char_sets_utf8.h|fribidi-char-sets.h|' ${WRKSRC}/src/jwm.h

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} jwm \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} jwm.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC} && ${INSTALL_DATA} example.jwmrc \
		${STAGEDIR}${PREFIX}/etc/system.jwmrc.sample)

.include <bsd.port.mk>
