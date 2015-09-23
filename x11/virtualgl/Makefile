# Created by: David Mackay <davidjx8p@gmail.com>
# $FreeBSD$

PORTNAME=	virtualgl
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	VirtualGL-${PORTVERSION}

MAINTAINER=	davidjx8p@gmail.com
COMMENT=	Redirects commands from an OpenGL app to another X server

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libturbojpeg.so:${PORTSDIR}/graphics/libjpeg-turbo

# due to the libjpeg-turbo requirement
ONLY_FOR_ARCHS=	amd64 i386

CMAKE_INSTALL_PREFIX=	${LOCALBASE}/VirtualGL
DOCSDIR=	${LOCALBASE}/VirtualGL/doc

USES=		cmake
USE_GL=		glu
USE_XORG=	x11 xau xcb xdamage xdmcp xext xfixes xxf86vm
CMAKE_ARGS=	-DTJPEG_INCLUDE_DIR=${LOCALBASE}/include -DTJPEG_LIBRARY=${LOCALBASE}/lib/libturbojpeg.so
USE_LDCONFIG=	${PREFIX}/VirtualGL/fakelib ${PREFIX}/VirtualGL/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
PLIST_SUB+=	AMD64="@comment "
.else
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	AMD64=""
.endif

.include <bsd.port.post.mk>
