# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.7.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3wm.org/downloads/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Improved dynamic tiling window manager

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libxcb-util.so:${PORTSDIR}/x11/xcb-util \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms \
		libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm \
		libev.so:${PORTSDIR}/devel/libev \
		libyajl.so:${PORTSDIR}/devel/yajl \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libpangocairo-1.0.so:${PORTSDIR}/x11-toolkits/pango \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libxcb-cursor.so:${PORTSDIR}/x11/xcb-util-cursor
RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-AnyEvent-I3>=0:${PORTSDIR}/devel/p5-AnyEvent-I3

USE_XORG=	x11 xcb
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
