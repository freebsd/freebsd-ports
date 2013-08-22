# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3lock
PORTVERSION=	2.5
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
		etc/pam.d/i3lock

MAN1=	i3lock.1

LDFLAGS+=	-liconv
USE_XORG=	x11 xcb xt xproto xext
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		iconv

.include <bsd.port.mk>
