PORTNAME=	xwayland-satellite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Xwayland outside your Wayland
WWW=		https://github.com/Supreeeme/xwayland-satellite

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor
RUN_DEPENDS=	Xwayland:x11-servers/xwayland

USES=		cargo llvm xorg
USE_GITHUB=	yes
USE_XORG=	xcb
GH_ACCOUNT=	Supreeeme
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs

.include <bsd.port.mk>
