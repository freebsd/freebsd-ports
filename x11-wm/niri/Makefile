PORTNAME=	niri
DISTVERSIONPREFIX=	v
DISTVERSION=	25.05.1
PORTREVISION=	2
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scrollable-tiling Wayland compositor
WWW=		https://github.com/YaLTeR/niri

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdisplay-info.so:sysutils/libdisplay-info \
		libseat.so:sysutils/seatd \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri

USES=		cargo gl gnome xorg
USE_GITHUB=	yes
USE_GL=		gbm
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	YaLTeR
CARGO_FEATURES=	--no-default-features dbus
PLIST_FILES=	bin/${PORTNAME} \
		share/wayland-sessions/${PORTNAME}.desktop \
		share/xdg-desktop-portal/${PORTNAME}-portals.conf

OPTIONS_DEFINE=	PIPEWIRE
OPTIONS_DEFAULT=PIPEWIRE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_USES=		llvm
PIPEWIRE_VARS=		CARGO_FEATURES+=xdp-gnome-screencast

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/unknown commit/${DISTVERSIONFULL}/' \
		${WRKSRC}/src/main.rs
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/main.rs
# Don't generate debuginfo as the binaries will be stripped
	@${REINPLACE_CMD} '/line-tables-only/d' ${WRKSRC}/Cargo.toml

post-install:
# Install extras similar to package.metadata.generate-rpm
.for f in resources/*.desktop resources/*-portals.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>
