# $FreeBSD$

PORTNAME=	pixman
PORTVERSION=	0.24.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Low-level pixel manipulation library

XORG_CAT=	lib
USE_AUTOTOOLS=	libtool
USE_PERL5_BUILD=yes
USE_GNOME=	ltverhack:9
CONFIGURE_ARGS=	--disable-gtk

OPTIONS_DEFINE=	SIMD

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS=	--disable-vmx --disable-arm-simd
. if ! ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--disable-mmx
. endif
. if ! ${MACHINE_CPU:Msse2}
CONFIGURE_ARGS+=	--disable-sse2
. endif
.endif

.include <bsd.port.mk>
