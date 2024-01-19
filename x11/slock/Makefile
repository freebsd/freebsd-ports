PORTNAME=	slock
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Simple X screen locker
WWW=		https://tools.suckless.org/slock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe xorg
CPE_VENDOR=	suckless
USE_XORG=	x11 xext xorgproto xrandr xt
MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}"

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include||;s|-L/usr/lib||;s|= -Os|+=|'\
		-e 's|-DHAVE_SHADOW_H|-DHAVE_PAM|' -e '/^LDFLAGS/s|$$| -lpam|' \
		${WRKSRC}/config.mk

.include <bsd.port.mk>
