# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.14.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3wm.org/downloads/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Improved dynamic tiling window manager

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libxcb-util.so:x11/xcb-util \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm \
		libev.so:devel/libev \
		libyajl.so:devel/yajl \
		libcairo.so:graphics/cairo \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpcre.so:devel/pcre \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-xrm.so:x11/xcb-util-xrm
RUN_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-AnyEvent-I3>=0:devel/p5-AnyEvent-I3

USES=		pkgconfig gmake iconv perl5 tar:bzip2
USE_XORG=	xcb
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ENV=	ac_cv_path_PATH_ASCIIDOC=""
USE_PERL5=	run
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
INSTALL_TARGET=	install-strip

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
