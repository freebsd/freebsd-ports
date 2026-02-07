PORTNAME=	pekwm
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.3.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-wm

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Light, Unobtrusive, and configurable windowmanager
WWW=		https://www.pekwm.se/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	gsed:textproc/gsed \
		xprop:x11/xprop

USES=		cmake compiler jpeg \
		localbase pkgconfig tar:bzip2 xorg
USE_XORG=	xft xpm x11 sm ice xext xinerama xrandr
USE_GITHUB=	yes
GH_ACCOUNT=	pekwm

OPTIONS_DEFINE=	PANGO
OPTIONS_DEFAULT=PANGO

PANGO_DESC=	Use Pango font support (both Cairo and Xft)

PANGO_LIB_DEPENDS= libpangocairo-1.0.so:x11-toolkits/pango \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz
PANGO_USES=	gnome gettext-runtime
PANGO_CMAKE_BOOL=ENABLE_PANGO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPANGO}
USE_GNOME=	glib20 cairo
.endif

.include <bsd.port.mk>
