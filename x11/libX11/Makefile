PORTNAME=	libX11
DISTVERSION=	1.8.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	xcb xtrans xorgproto
CPE_VENDOR=	x

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
