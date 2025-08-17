PORTNAME=	fuzzel
DISTVERSION=	1.13.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Application launcher for wlroots-based Wayland compositors
WWW=		https://codeberg.org/dnkl/fuzzel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.1:devel/tllist \
		wayland-protocols>=1.41:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig python:build xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/xdg/${PORTNAME}/${PORTNAME}.ini.sample" \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.ini.5.gz \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	CAIRO LIBRSVG2 PNG
OPTIONS_DEFAULT=CAIRO LIBRSVG2 PNG

CAIRO_USES=		gnome
CAIRO_USE=		GNOME=cairo
CAIRO_MESON_ENABLED=	enable-cairo

LIBRSVG2_USES=		gnome
LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ON=	-Dsvg-backend=librsvg
LIBRSVG2_MESON_OFF=	-Dsvg-backend=nanosvg
LIBRSVG2_IMPLIES=	CAIRO

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ON=		-Dpng-backend=libpng
PNG_MESON_OFF=		-Dpng-backend=none

post-patch:
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/completions/fish/${PORTNAME}.fish \
		${WRKSRC}/completions/zsh/_${PORTNAME} \
		${WRKSRC}/xdg.c
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/config.c \
		${WRKSRC}/doc/*.scd
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e "/ini/s/'[^']*/&', rename: &.sample/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
