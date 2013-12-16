# $FreeBSD$

PORTNAME=	pixman
PORTVERSION=	0.32.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Low-level pixel manipulation library

USES=		perl5
USE_PERL5=	build
XORG_CAT=	lib
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-gtk
USE_GNOME=	ltverhack:30

OPTIONS_DEFINE=	SIMD

.include <bsd.port.options.mk>

.if ! {PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS=	--disable-vmx --disable-arm-simd
. if ! ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--disable-mmx
. endif
. if ! ${MACHINE_CPU:Msse2}
CONFIGURE_ARGS+=	--disable-sse2
. endif
.endif

.include <bsd.port.mk>
