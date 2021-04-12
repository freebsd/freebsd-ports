PORTNAME=	fuzzel
DISTVERSION=	1.5.3
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Application launcher for wlroots-based Wayland compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tllist>=1.0.1:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	CAIRO LIBRSVG2 PNG
OPTIONS_DEFAULT=CAIRO LIBRSVG2 PNG

CAIRO_USES=		gnome
CAIRO_USE=		GNOME=cairo
CAIRO_MESON_ENABLED=	enable-cairo

LIBRSVG2_USES=		gnome
LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ENABLED=	enable-svg

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	enable-png

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/xdg.c

.include <bsd.port.mk>
