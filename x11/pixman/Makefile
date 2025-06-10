PORTNAME=	pixman
DISTVERSION=	0.46.2
CATEGORIES=	x11
MASTER_SITES=	https://cairographics.org/releases/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Low-level pixel manipulation library
WWW=		https://pixman.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe meson pkgconfig tar:xz
MESON_ARGS=	-Dloongson-mmi=disabled \
		-Dgtk=disabled \
		-Ddemos=disabled

OPTIONS_DEFINE=		OPENMP TEST
OPTIONS_DEFAULT=	OPENMP
OPTIONS_EXCLUDE_armv6=	OPENMP
OPTIONS_EXCLUDE_armv7=	OPENMP
OPTIONS_EXCLUDE_powerpc=OPENMP

OPENMP_MESON_ENABLED=	openmp

TEST_LIB_DEPENDS=	libpng.so:graphics/png
TEST_MESON_ENABLED=	libpng tests

.include <bsd.port.options.mk>

.if ${ARCH} == armv6
MESON_ARGS+=	-Darm-simd=enabled
.else
MESON_ARGS+=	-Darm-simd=disabled
.endif
.if ${ARCH} == armv7
MESON_ARGS+=	-Dneon=enabled
.else
MESON_ARGS+=	-Dneon=disabled
.endif
.if ${ARCH} == aarch64
MESON_ARGS+=	-Da64-neon=enabled
.else
MESON_ARGS+=	-Da64-neon=disabled
.endif
.if ${ARCH} == i386 || ${ARCH} == amd64
MESON_ARGS+=	-Dmmx=enabled \
		-Dsse2=enabled \
		-Dssse3=enabled
.else
MESON_ARGS+=	-Dmmx=disabled \
		-Dsse2=disabled \
		-Dssse3=disabled
.endif
.if ${ARCH:Mmips*}
MESON_ARGS+=	-Dmips-dspr2=enabled
.else
MESON_ARGS+=	-Dmips-dspr2=disabled
.endif
.if ${ARCH:Mpowerpc*}
MESON_ARGS+=	-Dvmx=enabled
.else
MESON_ARGS+=	-Dvmx=disabled
.endif
.if ${ARCH} == riscv64 && 0 # XXX Convert to elf_aux_info + HWCAP_ISA_V
MESON_ARGS+=	-Drvv=enabled
.else
MESON_ARGS+=	-Drvv=disabled
.endif

.include <bsd.port.mk>
