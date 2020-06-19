# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	xcb-util
PORTVERSION=	0.4.0
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	libxcb/libX11 extension/replacement libraries (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
SRC_DISTFILES=

DESCR=		${.CURDIR:H}/${PORTNAME}/pkg-descr
LIBDIR=		usr/lib${ARCH:S/i386//:S/amd64/64/}
PLIST_FILES=	${LIBDIR}/libxcb-util.so.1.0.0 ${LIBDIR}/libxcb-util.so.1

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBDIR}
	${LN} ${WRKSRC}/${LIBDIR}/libxcb-util.so.1.0.0	\
		${STAGEDIR}${PREFIX}/${LIBDIR}
	${LN} -s libxcb-util.so.1.0.0	\
		${STAGEDIR}${PREFIX}/${LIBDIR}/libxcb-util.so.1

.include <bsd.port.mk>
