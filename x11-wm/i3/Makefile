# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.19
CATEGORIES=	x11-wm
MASTER_SITES=	https://i3wm.org/downloads/ \
		http://i3wm.org/downloads/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Improved dynamic tiling window manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libev.so:devel/libev \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpcre.so:devel/pcre \
		libstartup-notification-1.so:x11/startup-notification \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxkbcommon.so:x11/libxkbcommon \
		libyajl.so:devel/yajl
RUN_DEPENDS=	p5-AnyEvent-I3>=0:devel/p5-AnyEvent-I3 \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny

USES=		compiler:c11 iconv localbase:ldflags meson perl5 pkgconfig tar:xz xorg
USE_XORG=	xcb
MESON_ARGS=	-Ddocs=false \
		-Dmans=false
LDFLAGS+=	${ICONV_LIB}
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	i3-gaps

.include <bsd.port.mk>
