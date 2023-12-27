PORTNAME=	wscreensaver
DISTVERSION=	s20231227
DISTVERSIONSUFFIX=	-0-g2155bb8f
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~mstoeckl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fork of xscreensaver to draw animated wallpapers on Wayland
WWW=		https://sr.ht/~mstoeckl/wscreensaver/

LICENSE=	MIT

LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

USES=		gl gnome meson perl5 pkgconfig
USE_GL=		egl glesv2 glu
USE_GNOME=	gdkpixbuf2
USE_PERL5=	build # pre-build (bin2c)
WRKSRC_SUBDIR=	wayland
CFLAGS+=	-Wno-incompatible-function-pointer-types # clang
LDFLAGS+=	-lpthread # XXX dependency('threads')

post-patch:
# Skip configure
	@${SED} '/@SET_MAKE@/d; s,@srcdir@,.,; s,@top_srcdir@,../..,' \
		${WRKSRC:H}/hacks/images/Makefile.in \
		>${WRKSRC:H}/hacks/images/Makefile
# Disambiguate shell completions
	@${REINPLACE_CMD} -e "s/'xscreensaver-'/'${PORTNAME}-'/" \
		${WRKSRC}/meson.build

pre-build:
# Meson doesn't generate *_png.h yet
	@${SETENV} ${MAKE_ENV} ${BSDMAKE} -C ${WRKSRC:H}/hacks/images

.include <bsd.port.mk>
