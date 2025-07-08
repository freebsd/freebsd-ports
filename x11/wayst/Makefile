PORTNAME=	wayst
DISTVERSION=	g20250601
CATEGORIES=	x11 wayland

MAINTAINER=	seafork@disroot.org
COMMENT=	Simple terminal emulator for Wayland and X11
WWW=		https://github.com/91861/wayst

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libutf8proc.so:textproc/utf8proc

USES=		gl gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	91861
GH_TAGNAME=	f5a6c22

USE_GL=		egl gl

PLIST_FILES=	bin/wayst

OPTIONS_DEFAULT=	WAYLAND X11
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	WAYLAND X11

WAYLAND_DESC=	Use Wayland as the windowing protocol
X11_DESC=	Use X11 as the windowing protocol

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_MAKE_ARGS=	window_protocol+="wayland"

X11_USES=	xorg
X11_USE=	XORG=x11,xrandr,xrender
X11_MAKE_ARGS=	window_protocol+="x11"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wayst

.include <bsd.port.mk>
