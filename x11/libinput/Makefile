# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.6.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libepoll-shim.so:devel/libepoll-shim \
		libwacom.so:x11/libwacom \
		libudev.so:devel/libudev-devd \
		libmtdev.so:devel/libmtdev

USES=		autoreconf gmake libtool pathfix pkgconfig tar:xz
EXTRACT_AFTER_ARGS=	--exclude include # evdev-proto
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e 's|program_invocation_short_name|getprogname()|' \
	    ${WRKSRC}/tools/libinput-list-devices.c \
	    ${WRKSRC}/tools/ptraccel-debug.c ${WRKSRC}/tools/shared.c

.include <bsd.port.mk>
