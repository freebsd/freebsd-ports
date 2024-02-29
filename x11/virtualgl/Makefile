PORTNAME=	virtualgl
DISTVERSION=	3.1.1
CATEGORIES=	x11 graphics
MASTER_SITES=	https://github.com/VirtualGL/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	VirtualGL-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Redirects commands from an OpenGL app to another X server
WWW=		https://www.virtualgl.org

LICENSE=	LGPL21 WXWINDOWS
LICENSE_COMB=	multi
LICENSE_NAME_WXWINDOWS=	wxWindows Library Licence, Version 3.1
LICENSE_FILE_LGPL21=	${WRKSRC}/LGPL.txt
LICENSE_FILE_WXWINDOWS=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_WXWINDOWS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	xcb-util-keysyms>0:x11/xcb-util-keysyms
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libturbojpeg.so:graphics/libjpeg-turbo

USES=		cmake gl localbase xorg
USE_GL=		egl gl glu
USE_XORG=	x11 xcb xext xtst
USE_LDCONFIG=	${PREFIX}/VirtualGL/lib

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DTJPEG_INCLUDE_DIR=${LOCALBASE}/include \
		-DTJPEG_LIBRARY=${LOCALBASE}/lib/libturbojpeg.so
CMAKE_ON=	VGL_FAKEXCB VGL_SYSTEMFLTK
CMAKE_INSTALL_PREFIX=	${LOCALBASE}/VirtualGL

# Some versioned symbols in virtualgl are undefined when libvglfaker.so
# is linked. Suppress errors with lld >= 17 due to these undefined
# symbols.
LDFLAGS+=	-Wl,--undefined-version

DOCSDIR=	${LOCALBASE}/VirtualGL/doc
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS OPENCL OPENSSL XVIDEO
OPTIONS_DEFAULT=	OPENCL
OPTIONS_SUB=		yes

OPENCL_CMAKE_BOOL=	VGL_FAKEOPENCL
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_DESC=		Build OpenCL interposer library

OPENSSL_CMAKE_BOOL=	VGL_USESSL
OPENSSL_USES=		ssl

XVIDEO_CMAKE_BOOL=	VGL_USEXV
XVIDEO_USE=		XORG=xv

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv7" || ${ARCH} == "i386" || ${ARCH} == "powerpc"
PLIST_SUB+=	AMD64="@comment " \
		I386=""
.else
PLIST_SUB+=	AMD64="" \
		I386="@comment "
.endif

.include <bsd.port.post.mk>
