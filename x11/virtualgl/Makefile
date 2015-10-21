# Created by: David Mackay <davidjx8p@gmail.com>
# $FreeBSD$

PORTNAME=	virtualgl
PORTVERSION=	2.4.1
CATEGORIES=	x11 graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	VirtualGL-${PORTVERSION}

MAINTAINER=	davidjx8p@gmail.com
COMMENT=	Redirects commands from an OpenGL app to another X server

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libturbojpeg.so:${PORTSDIR}/graphics/libjpeg-turbo \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms

# due to the libjpeg-turbo requirement
ONLY_FOR_ARCHS=	amd64 i386

CMAKE_INSTALL_PREFIX=	${LOCALBASE}/VirtualGL
DOCSDIR=	${LOCALBASE}/VirtualGL/doc

USES=		cmake compiler:c++11-lang
USE_GL=		gl glu
USE_XORG=	x11 xau xcb xdamage xdmcp xext xfixes xxf86vm
CMAKE_ARGS=	-DTJPEG_INCLUDE_DIR=${LOCALBASE}/include\
		-DTJPEG_LIBRARY=${LOCALBASE}/lib/libturbojpeg.so\
		-DVGL_FAKEXCB=on -DVGL_SYSTEMFLTK=on -DVGL_SYSTEMGLX=on
USE_LDCONFIG=	${PREFIX}/VirtualGL/fakelib ${PREFIX}/VirtualGL/lib
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
PLIST_SUB+=	AMD64="@comment "
.else
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	AMD64=""
.endif

.include <bsd.port.post.mk>
