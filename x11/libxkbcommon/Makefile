PORTNAME=	libxkbcommon
PORTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	https://xkbcommon.org/download/
DIST_SUBDIR=	xorg/lib

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Keymap handling library for toolkits and window systems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xkeyboard-config>0:x11/xkeyboard-config

USES=		bison gnome meson pkgconfig tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Denable-docs=false \
		-Denable-wayland=false \
		-Dx-locale-root="${PREFIX}/lib/X11/locale" \
		${MESON_ARGS_${OPSYS}_${OSREL:R}}
MESON_ARGS_FreeBSD_11=	-Ddefault-rules=xorg

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=	xorg
X11_USE=	XORG=xcb
X11_MESON_TRUE=	enable-x11

.include <bsd.port.mk>
