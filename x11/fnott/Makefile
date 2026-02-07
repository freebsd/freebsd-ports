PORTNAME=	fnott
DISTVERSION=	1.8.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Keyboard-driven notification daemon for wlroots-based compositors
WWW=		https://codeberg.org/dnkl/fnott

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.1:devel/tllist \
		wayland-protocols>=1.32:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libepoll-shim.so:devel/libepoll-shim \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c11 meson pkgconfig xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_MESON_ENABLED=	docs

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/config.c \
		${WRKSRC}/doc/${PORTNAME}.ini.5.scd
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/xdg.c
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e "/install.*sysconfdir/s/'[^']*/&', rename: &.sample/1" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
