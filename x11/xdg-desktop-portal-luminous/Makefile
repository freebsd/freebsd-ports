PORTNAME=	xdg-desktop-portal-luminous
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for wlroots
WWW=		https://github.com/waycrate/xdg-desktop-portal-luminous

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal \
		slurp:x11/slurp

USES=		cargo gnome llvm meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo pango
GH_ACCOUNT=	waycrate
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
PLIST_FILES=	lib/systemd/user/${PORTNAME}.service \
		libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.luminous.service \
		share/xdg-desktop-portal/portals/luminous.portal

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs
# Make each cargo subcommand very verbose
# Adjust for CARGO_TARGET_DIR outside of meson.global_source_root()
	@${REINPLACE_CMD} -e "s/'build',/ & '--verbose', '--verbose',/" \
		-e "s,'target','..' / & ," \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
