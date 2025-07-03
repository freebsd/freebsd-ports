PORTNAME=	eww
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	6
CATEGORIES=	x11 wayland
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ElKowars wacky widgets
WWW=		https://elkowar.github.io/eww

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	mismatched types: expected \`i32\`, found \`i64\`

LIB_DEPENDS=	libdbusmenu-glib.so:devel/libdbusmenu

FLAVORS=			x11 wayland
wayland_LIB_DEPENDS=		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
wayland_CONFLICTS_INSTALL=	${PORTNAME}-x11
x11_CONFLICTS_INSTALL=		${PORTNAME}-wayland

USES=		cargo gnome
USE_GITHUB=	yes
GH_ACCOUNT=	elkowar
USE_GNOME=	cairo gdkpixbuf gtk30

CARGO_FEATURES=		${FLAVOR} --no-default-features
CARGO_INSTALL_PATH=	crates/${PORTNAME}
CARGO_ENV=		RUSTC_BOOTSTRAP=1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
