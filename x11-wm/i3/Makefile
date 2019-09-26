# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.17.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3wm.org/downloads/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Improved dynamic tiling window manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

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

USES=		compiler:c11 gmake iconv localbase perl5 pkgconfig tar:bzip2 \
		xorg
USE_XORG=	xcb
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ENV=	ac_cv_path_PATH_ASCIIDOC=""
LDFLAGS+=	${ICONV_LIB}
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	i3-gaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
