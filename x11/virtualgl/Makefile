# Created by: David Mackay <davidjx8p@gmail.com>
# $FreeBSD$

PORTNAME=	virtualgl
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	VirtualGL-${PORTVERSION}

MAINTAINER=	davidjx8p@gmail.com
COMMENT=	Redirects commands from an OpenGL app to another X server

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libxcb-keysyms.so:x11/xcb-util-keysyms

ONLY_FOR_ARCHS=	amd64 i386

CMAKE_INSTALL_PREFIX=	${LOCALBASE}/VirtualGL
DOCSDIR=	${LOCALBASE}/VirtualGL/doc

USES=		cmake compiler:c++11-lang
USE_GL=		gl glu
USE_XORG=	x11 xcb xext
CMAKE_ARGS=	-DTJPEG_INCLUDE_DIR=${LOCALBASE}/include\
		-DTJPEG_LIBRARY=${LOCALBASE}/lib/libturbojpeg.so\
		-DVGL_FAKEXCB=on -DVGL_SYSTEMFLTK=on -DVGL_SYSTEMGLX=on
USE_LDCONFIG=	${PREFIX}/VirtualGL/fakelib ${PREFIX}/VirtualGL/lib
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	OPENSSL XVIDEO

OPENSSL_CMAKE_ON=	-DVGL_USESSL:BOOL=ON
OPENSSL_CMAKE_OFF=	-DVGL_USESSL:BOOL=OFF
OPENSSL_USE=	OPENSSL=yes

XVIDEO_CMAKE_ON=	-DVGL_USEXV:BOOL=ON
XVIDEO_CMAKE_OFF=	-DVGL_USEXV:BOOL=OFF
XVIDEO_USE=	XORG=xv

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
PLIST_SUB+=	AMD64="@comment "
.else
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	AMD64=""
.endif

.include <bsd.port.post.mk>
