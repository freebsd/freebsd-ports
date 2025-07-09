PORTNAME=	babl
PORTVERSION=	0.1.114
CATEGORIES=	x11
MASTER_SITES=	GIMP

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dynamic pixel format conversion library
WWW=		https://www.gegl.org/babl/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblcms2.so:graphics/lcms2

USES=		compiler:c11 gnome meson pathfix pkgconfig tar:xz vala:build

USE_GNOME=	introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgi-docgen=disabled -Dwith-docs=false

BABL_SHLIB=	0.213.1
BABL_VER=	0.1
PLIST_SUB+=	BABL_SHLIB=${BABL_SHLIB} BABL_VER=${BABL_VER}

OPTIONS_DEFINE_amd64=	AVX2 F16C MMX SSE2 SSE41 SSE
OPTIONS_DEFINE_i386=	AVX2 F16C MMX SSE2 SSE41 SSE
OPTIONS_DEFAULT_amd64=	MMX SSE2 SSE

AVX2_DESC=		Use AVX2 optimized routines
F16C_DESC=		Use F16C optimized routines
SSE2_DESC=		Use SSE2 optimized routines
SSE41_DESC=		Use SSE4.1 optimized routines

AVX2_IMPLIES=		SSE41
AVX2_MESON_ON=		-Denable-avx2=true
AVX2_MESON_OFF=		-Denable-avx2=false

F16C_IMPLIES=		MMX
F16C_MESON_ON=		-Denable-f16c=true
F16C_MESON_OFF=		-Denable-f16c=false

MMX_MESON_ON=		-Denable-mmx=true
MMX_MESON_OFF=		-Denable-mmx=false

SSE2_IMPLIES=		SSE
SSE2_MESON_ON=		-Denable-sse2=true
SSE2_MESON_OFF=		-Denable-sse2=false

SSE41_IMPLIES=		SSE2
SSE41_MESON_ON=		-Denable-sse4_1=true
SSE41_MESON_OFF=	-Denable-sse4_1=false

SSE_IMPLIES=		MMX
SSE_MESON_ON=		-Denable-sse=true
SSE_MESON_OFF=		-Denable-sse=false

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARM="@comment "
.elif ${ARCH} == "armv6" || ${ARCH} == "armv7"
PLIST_SUB+=	AMD64="@comment " ARM=""
.else
PLIST_SUB+=	AMD64="@comment " ARM="@comment "
.endif

.include <bsd.port.post.mk>
