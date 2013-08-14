# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3lock
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/${PORTNAME}/ \
		http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Slightly improved screen locker based on slock

LICENSE=	BSD

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms \
		xcb-image:${PORTSDIR}/x11/xcb-util-image \
		ev.4:${PORTSDIR}/devel/libev

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
