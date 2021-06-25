# Created by: Eric Anholt <anholt@FreeBSD.org>

PORTNAME=	libX11
DISTVERSION=	1.7.2
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

LICENSE=	MIT

USES=		cpe xorg xorg-cat:lib
USE_XORG=	xcb xtrans xorgproto
CPE_VENDOR=	x

CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib \
			--without-xmlto \
			--with-perl=no \
			--disable-specs
CONFIGURE_ENV+=	ac_cv_path_PS2PDF=""
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
