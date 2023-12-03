PORTNAME=	virtualgl
DISTVERSION=	3.1
CATEGORIES=	x11 graphics
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}
DISTNAME=	VirtualGL-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Redirects commands from an OpenGL app to another X server
WWW=		https://www.virtualgl.org

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cmake compiler:c++11-lang gl localbase xorg
USE_GL=		egl gl glu
USE_XORG=	x11 xcb xext xtst
USE_LDCONFIG=	${PREFIX}/VirtualGL/lib

CMAKE_ARGS=	-DTJPEG_INCLUDE_DIR=${LOCALBASE}/include \
		-DTJPEG_LIBRARY=${LOCALBASE}/lib/libturbojpeg.so \
		-DVGL_FAKEXCB=on -DVGL_SYSTEMFLTK=on \
		-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}
CMAKE_INSTALL_PREFIX=	${LOCALBASE}/VirtualGL

# Some versioned symbols in virtualgl are undefined when libvglfaker.so
# is linked. Suppress errors with lld >= 17 due to these undefined
# symbols.
LDFLAGS+=	-Wl,--undefined-version

DOCSDIR=	${LOCALBASE}/VirtualGL/doc

OPTIONS_DEFINE=	OPENCL OPENSSL XVIDEO DOCS
OPTIONS_DEFAULT=	OPENCL
OPTIONS_SUB=	yes

OPENCL_CMAKE_BOOL=	VGL_FAKEOPENCL
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_DESC=		Build OpenCL interposer library

OPENSSL_CMAKE_BOOL=	VGL_USESSL
OPENSSL_USES=		ssl

XVIDEO_CMAKE_BOOL=	VGL_USEXV
XVIDEO_USE=	XORG=xv

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv7" || ${ARCH} == "i386" || ${ARCH} == "powerpc"
PLIST_SUB+=	I386="" \
		AMD64="@comment "
.else
PLIST_SUB+=	I386="@comment " \
		AMD64=""
.endif

.include <bsd.port.post.mk>
