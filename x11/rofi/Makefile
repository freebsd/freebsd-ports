# $FreeBSD$

PORTNAME=	rofi
PORTVERSION=	1.6.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/davatorium/rofi/releases/download/${PORTVERSION}/

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	Window switcher, run dialog and dmenu replacement

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxkbcommon-x11.so:x11/libxkbcommon

USES=		bison gnome meson pkgconfig shebangfix xorg
USE_GNOME=	cairo gdkpixbuf2 librsvg2 pango
USE_XORG=	xcb
SHEBANG_FILES=	script/get_git_rev.sh \
		script/rofi-sensible-terminal
bash_CMD=	/bin/sh

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	checkmk:devel/check
TEST_MESON_ENABLED=	check

post-patch:
# Fix rofi-theme-selector which assumes we have GNU sed
	@${REINPLACE_CMD} 's|$${SED} -i |$${SED} -i "" |' \
		${WRKSRC}/script/rofi-theme-selector

.include <bsd.port.mk>
