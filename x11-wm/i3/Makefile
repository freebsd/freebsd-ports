# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.12
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
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-AnyEvent-I3>=0:devel/p5-AnyEvent-I3

USE_XORG=	xcb
USES=		pkgconfig iconv gmake perl5 tar:bzip2
USE_PERL5=	run
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/i3.config
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/i3.config
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}/|g' ${WRKSRC}/man/Makefile
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3.1
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3-msg.1
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3-input.1
	@${REINPLACE_CMD} -e 's|.SILENT||g' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|-Iinclude|-Iinclude -Isrc|g' \
			  -e 's|-liconv|${ICONV_LIB}|' \
			  -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/common.mk

post-install:
	@${INSTALL_DATA} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/i3 \
		${STAGEDIR}${PREFIX}/bin/i3bar \
		${STAGEDIR}${PREFIX}/bin/i3-config-wizard \
		${STAGEDIR}${PREFIX}/bin/i3-msg \
		${STAGEDIR}${PREFIX}/bin/i3-input \
		${STAGEDIR}${PREFIX}/bin/i3-nagbar \
		${STAGEDIR}${PREFIX}/bin/i3-dump-log

.include <bsd.port.mk>
