PORTNAME=	fvwm3
DISTVERSION=	1.1.4
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/fvwmorg/fvwm3/releases/download/${DISTVERSION}/ \
		http://fvwm.sourceforge.net/generated/icon_download/:icons

MAINTAINER=	nyan@FreeBSD.org
COMMENT=	F? Virtual Window Manager
WWW=		https://www.fvwm.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 cpe localbase:ldflags meson perl5 pkgconfig \
		python shebangfix xorg
CPE_VENDOR=	fvwm
CPE_PRODUCT=	fvwm
USE_XORG=	ice sm x11 xext xft xrandr xrender xt xtrans
SHEBANG_FILES=	bin/FvwmCommand.in bin/fvwm-menu-desktop.in
python_OLD_CMD=	@PYTHON@

CONFLICTS_INSTALL=	fvwm

BINARY_ALIAS=		python3=${PYTHON_CMD}

PLIST_SUB=		DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		FRIBIDI GO ICONS ICONV MANPAGES NLS PNG READLINE SVG \
			XCURSOR XPM
OPTIONS_DEFAULT=	FRIBIDI GO ICONV MANPAGES PNG READLINE XCURSOR
OPTIONS_SUB=		yes
GO_DESC=		Build and install modules written in Go

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_MESON_ENABLED=	bidi

GO_USES=		go:no_targets
GO_MESON_ENABLED=	golang

FVWM_ICONS=		fvwm_icons-20070101
ICONS_IMPLIES=		XPM
ICONS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FVWM_ICONS}.tar.bz2:icons

ICONV_USES=		iconv:translit
ICONV_MESON_ENABLED=	iconv

MANPAGES_BUILD_DEPENDS=	rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
MANPAGES_MESON_TRUE=	mandoc

NLS_USES=		gettext
NLS_MESON_ENABLED=	nls

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png

READLINE_USES=		readline
READLINE_MESON_ENABLED=	readline

SVG_USES=		gnome
SVG_USE=		GNOME=librsvg2
SVG_MESON_ENABLED=	svg

XCURSOR_USE=		XORG=xcursor,xfixes
XCURSOR_MESON_ENABLED=	xcursor xfixes

XPM_USE=		XORG=xpm
XPM_MESON_ENABLED=	xpm

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${LOCALBASE}/etc/,g' \
		${WRKSRC}/bin/fvwm-menu-desktop.in

post-install-GO-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/FvwmPrompt

post-install-ICONS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fvwm3/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${FVWM_ICONS}/*.xpm \
		${STAGEDIR}${PREFIX}/share/fvwm3/pixmaps

.include <bsd.port.mk>
