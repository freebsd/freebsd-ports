# New ports collection makefile for:	i3lock
# Date created:		2009-05-22
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3lock
PORTVERSION=	2.4
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/${PORTNAME}/ \
		http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Slightly improved screen locker based on slock

LICENSE=	BSD

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-keysyms.1:${PORTSDIR}/x11/xcb-util-keysyms \
		xcb-image.0:${PORTSDIR}/x11/xcb-util-image \
		ev.4:${PORTSDIR}/devel/libev

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}" \
		MANDIR="${MANPREFIX}/man"

PLIST_FILES=	bin/i3lock \
		etc/pam.d/i3lock

MAN1=	i3lock.1

LDFLAGS+=	-liconv
MAKE_JOBS_SAFE=	yes
USE_XORG=	x11 xt xproto xext
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

.include <bsd.port.mk>
