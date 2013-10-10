# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3lock
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/${PORTNAME}/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Slightly improved screen locker based on slock

LICENSE=	BSD

LIB_DEPENDS=	libcairo.so.2:${PORTSDIR}/graphics/cairo \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms \
		libxcb-image.so:${PORTSDIR}/x11/xcb-util-image \
		libev.so.4:${PORTSDIR}/devel/libev \
		libxkbfile.so:${PORTSDIR}/x11/libxkbfile \
		libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}" \
		MANDIR="${MANPREFIX}/man"

PLIST_FILES=	bin/i3lock \
		man/man1/i3lock.1.gz

LDFLAGS+=	${ICONV_LIB}
USE_XORG=	x11 xcb xt xproto xext
USE_BZIP2=	yes
USES=		gmake iconv pkgconfig

post-install:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/i3lock

.include <bsd.port.mk>
