# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libX11
PORTVERSION=	1.6.10
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/lib/libx11/-/commit/
PATCHFILES=	93fce3f4e79cbc737d6468a4f68ba3de1b83953b.diff:-p1

LICENSE=	MIT

USES=		cpe perl5 xorg xorg-cat:lib
USE_XORG=	xcb xtrans xorgproto
USE_PERL5=	build
CPE_VENDOR=	x

CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib \
			--without-xmlto \
			--disable-specs
CONFIGURE_ENV+=	ac_cv_path_PS2PDF=""
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^install-data-am:/,/^$$/ \
		s/install-specDATA//' ${WRKSRC}/nls/Makefile.in

.include <bsd.port.mk>
