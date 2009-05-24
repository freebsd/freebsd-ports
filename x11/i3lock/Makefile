# New ports collection makefile for:	i3lock
# Date created:		2009-05-22
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3lock
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://i3.zekjur.net/${PORTNAME}/ \
		http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Slightly improved screen locker based on slock

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}" \
		MANDIR="${MANPREFIX}/man"
PLIST_FILES=	bin/i3lock

MAN1=	i3lock.1

MAKE_JOBS_SAFE=	yes
USE_XORG=	x11 xt xproto xext

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include||;s|-L/usr/lib||;s|= -Os|+=|'\
		-e 's|-DHAVE_SHADOW_H||' ${WRKSRC}/config.mk

.include <bsd.port.mk>
