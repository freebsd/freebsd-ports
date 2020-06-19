# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	xcb-util-image
PORTVERSION=	0.4.0
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Port of Xlib's XImage and XShmImage functions (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
SRC_DISTFILES=

DESCR=		${.CURDIR:H}/${PORTNAME}/pkg-descr
LIBDIR=		usr/lib${ARCH:S/i386//:S/amd64/64/}
PLIST_FILES=	${LIBDIR}/libxcb-image.so.0.0.0 ${LIBDIR}/libxcb-image.so.0

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBDIR}
	${LN} ${WRKSRC}/${LIBDIR}/libxcb-image.so.0.0.0	\
		${STAGEDIR}${PREFIX}/${LIBDIR}
	${LN} -s libxcb-image.so.0.0.0	\
		${STAGEDIR}${PREFIX}/${LIBDIR}/libxcb-image.so.0

.include <bsd.port.mk>
