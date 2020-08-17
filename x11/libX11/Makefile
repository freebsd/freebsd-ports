# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libX11
PORTVERSION=	1.6.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/lib/libx11/-/commit/
PATCHFILES+=	6dd618e5ea8e7558dd8e99a2777ab7b69211789c.diff:-p1
PATCHFILES+=	d15c24c8b44be5e4054c8ecd0ff9dcf2c8e18e5b.diff:-p1

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
