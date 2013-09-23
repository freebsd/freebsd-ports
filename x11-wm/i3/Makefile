# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.6
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3wm.org/downloads/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Improved dynamic tiling window manager

LICENSE=	BSD

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libxcb-util.so:${PORTSDIR}/x11/xcb-util \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms \
		libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm \
		libev.so:${PORTSDIR}/devel/libev \
		libyajl.so:${PORTSDIR}/devel/yajl \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libpangocairo-1.0.so:${PORTSDIR}/x11-toolkits/pango \
		libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-AnyEvent-I3>=0:${PORTSDIR}/devel/p5-AnyEvent-I3

USE_XORG=	x11 xcb xcursor
USES=		pkgconfig iconv gmake perl5
USE_BZIP2=	yes
USE_PERL5=	run
MAKE_JOBS_UNSAFE=	yes

post-extract:
	@cd ${WRKSRC} && ${CP} i3.config config.sample
	@cd ${WRKSRC} && ${CP} i3.config.keycodes config.keycodes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/config.sample
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/config.keycodes
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

.include <bsd.port.mk>
