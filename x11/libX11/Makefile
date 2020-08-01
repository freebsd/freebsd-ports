# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libX11
PORTVERSION=	1.6.9
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/lib/libx11/-/commit/
PATCHFILES=	0e6561efcfaa0ae7b5c74eac7e064b76d687544e.diff:-p1
PATCHFILES+=	388b303c62aa35a245f1704211a023440ad2c488.diff:-p1
PATCHFILES+=	2fcfcc49f3b1be854bb9085993a01d17c62acf60.diff:-p1
PATCHFILES+=	1a566c9e00e5f35c1f9e7f3d741a02e5170852b2.diff:-p1
PATCHFILES+=	1703b9f3435079d3c6021e1ee2ec34fd4978103d.diff:-p1

LICENSE=	MIT

USES=		cpe perl5 xorg xorg-cat:lib
USE_XORG=	xau xcb xdmcp xtrans xorgproto
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
