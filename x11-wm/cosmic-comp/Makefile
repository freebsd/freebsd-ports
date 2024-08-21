PORTNAME=	cosmic-comp
PORTVERSION=	s20240821
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Compositor for the COSMIC desktop environment
WWW=		https://github.com/pop-os/cosmic-comp

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libseat.so:sysutils/seatd \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri \
		vulkan-loader>0:graphics/vulkan-loader \
		Xwayland:x11-servers/xwayland

USES=		cargo gl xorg
USE_GITHUB=	yes
USE_GL=		gbm
USE_XORG=	pixman
GH_ACCOUNT=	pop-os
GH_TAGNAME=	epoch-1.0.0-alpha.1-19-gca6f05c
GH_TUPLE=	pop-os:iced:0.4.2-2011-ge31e29e9:iced/../${WRKSRC_crate_iced:T}/iced
CARGO_ENV=	RUSTC_BOOTSTRAP=cosmic # files/patch-rust-1.79
CARGO_FEATURES=	--no-default-features # disable systemd
PLIST_FILES=	bin/${PORTNAME} \
		share/cosmic/com.system76.CosmicSettings.Shortcuts/v1/defaults/keybindings.ron \
		share/wayland-sessions/${PORTNAME:S/-comp//}.desktop \

.if ${MACHINE_ARCH} == i386 || ${MACHINE_ARCH:Marmv?}
# https://github.com/rust-lang/rust/issues/85598
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
# XXX Strip double / to help "make cargo-crates"
	@${REINPLACE_CMD} -e 's,\(smithay\)//,\1/,' \
		${WRKSRC}/Cargo.lock
# XXX Drop [patch.<url>] section to help "make cargo-configure"
	@${REINPLACE_CMD} -e '/\[patch/,$$d' \
		${WRKSRC}/Cargo.toml
# /sys by default is a symlink to /usr/src/sys
	@${REINPLACE_CMD} -e 's,/sys,${LINUXBASE}&,' \
		${WRKSRC}/src/debug.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
# Install extras similar to ${WRKSRC}/Makefile
.for f in data/*.desktop data/*.ron
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>
