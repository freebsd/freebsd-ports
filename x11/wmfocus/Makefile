PORTNAME=	wmfocus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	14
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c646aa39614b.patch:-p1 # https://github.com/svenstaro/wmfocus/pull/72

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Visually focus windows by label
WWW=		https://github.com/svenstaro/wmfocus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxkbcommon>0:x11/libxkbcommon
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cargo gnome python:3.4+,build xorg
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_XORG=	x11 xcb
GH_ACCOUNT=	svenstaro
CARGO_FEATURES=	i3
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# lang/python3 cannot be used as a dependency
	@${REINPLACE_CMD} -e 's/"python3"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/cargo-crates/xcb-*/build.rs

.include <bsd.port.mk>
