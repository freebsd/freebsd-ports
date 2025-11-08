PORTNAME=	xmoji
DISTVERSION=	0.8
CATEGORIES=	x11
MASTER_SITES=	${WWW}/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Plain X11 emoji keyboard
WWW=		https://github.com/Zirias/xmoji

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng16.so:graphics/png \
		libposercore.so:devel/poser \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gmake pkgconfig tar:xz xorg
USE_XORG=	xcb

MAKEFILE=	GNUmakefile
MAKE_ARGS=	BUNDLED_POSER=off

OPTIONS_DEFINE=		DOCS NLS SVG TRACE
OPTIONS_DEFAULT=	SVG
OPTIONS_SUB=		yes
SVG_DESC=		Support glyphs in SVG format
TRACE_DESC=		Build with X11 request tracing (for debugging)
NLS_MAKE_ARGS_OFF=	WITH_NLS=off
SVG_MAKE_ARGS_OFF=	WITH_SVG=off
TRACE_MAKE_ARGS=	TRACE=on

.include <bsd.port.mk>
