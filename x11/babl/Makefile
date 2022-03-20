# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	babl
PORTVERSION=	0.1.88
CATEGORIES=	x11
MASTER_SITES=	GIMP

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	9a74120fbdd2.patch:-p1 # https://gitlab.gnome.org/GNOME/babl/-/merge_requests/45

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dynamic pixel format conversion library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	liblcms2.so:graphics/lcms2

USES=		compiler:c11 gnome libtool localbase meson pathfix pkgconfig tar:xz

USE_LDCONFIG=	yes
USE_GNOME=	introspection:build

OPTIONS_DEFINE=	SIMD
OPTIONS_DEFAULT=SIMD

SIMD_MESON_OFF=	-Denable-mmx=false -Denable-sse=false \
		-Denable-sse2=false -Denable-sse4_1=false \
		-Denable-avx2=false -Denable-f16c=false

.include <bsd.port.mk>
