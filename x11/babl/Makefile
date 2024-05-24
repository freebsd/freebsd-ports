PORTNAME=	babl
PORTVERSION=	0.1.108
CATEGORIES=	x11
MASTER_SITES=	GIMP

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dynamic pixel format conversion library
WWW=		https://www.gegl.org/babl/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblcms2.so:graphics/lcms2

USES=		gnome libtool localbase meson pathfix pkgconfig tar:xz vala:build

USE_LDCONFIG=	yes
USE_GNOME=	introspection:build

MESON_ARGS=	-Dgi-docgen=disabled -Dwith-docs=false

OPTIONS_DEFINE=	SIMD
OPTIONS_DEFAULT_amd64=SIMD
OPTIONS_EXCLUDE_i386=SIMD

SIMD_MESON_OFF=	-Denable-mmx=false -Denable-sse=false \
		-Denable-sse2=false -Denable-sse4_1=false \
		-Denable-avx2=false -Denable-f16c=false

BABL_SHLIB=	0.207.1
BABL_VER=	0.1
PLIST_SUB+=	BABL_SHLIB=${BABL_SHLIB} BABL_VER=${BABL_VER}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c11
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARM="@comment "
.elif ${ARCH} == "armv6" || ${ARCH} == "armv7"
PLIST_SUB+=	AMD64="@comment " ARM=""
.else
PLIST_SUB+=	AMD64="@comment " ARM="@comment "
.endif

.include <bsd.port.post.mk>
