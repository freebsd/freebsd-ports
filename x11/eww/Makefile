PORTNAME=	eww
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	13
CATEGORIES=	x11 wayland
PKGNAMESUFFIX=	-${FLAVOR}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f97d5919f3a4.patch:-p1 # https://github.com/elkowar/eww/pull/711

MAINTAINER=	DtxdF@disroot.org
COMMENT=	ElKowars wacky widgets
WWW=		https://elkowar.github.io/eww

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	mismatched types: expected \`i32\`, found \`i64\`

FLAVORS=			x11 wayland
wayland_LIB_DEPENDS=		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
wayland_CONFLICTS_INSTALL=	${PORTNAME}-x11
x11_CONFLICTS_INSTALL=		${PORTNAME}-wayland

USES=		cargo gnome
USE_GITHUB=	yes
GH_ACCOUNT=	elkowar
USE_GNOME=	cairo gdkpixbuf2 gtk30

CARGO_FEATURES=		--no-default-features ${FLAVOR}
CARGO_INSTALL_PATH=	crates/${PORTNAME}
CARGO_ENV=	RUSTC_BOOTSTRAP=1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
