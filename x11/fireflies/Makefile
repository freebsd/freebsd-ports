PORTNAME=		fireflies
DISTVERSIONPREFIX=	v
DISTVERSION=		2.08
PORTREVISION=	1
CATEGORIES=		x11

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Fireflies screensaver, for use with xscreensaver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		autoreconf gl gmake localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	mpcomplete
USE_GL=		gl glu
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bindir=${PREFIX}/${XSSHACKSDIR} \
		--with-confdir=${PREFIX}/${XSSCONFDIR} \
		ac_cv_lib_jpeg_jpeg_start_compress=no \
		ac_cv_lib_png_png_read_image=no \
		ac_cv_lib_tiff_TIFFOpen=no

CPPFLAGS+=	-DHAVE_BOOL
LDFLAGS+=	-largp

PLIST_FILES=	${XSSHACKSDIR}/fireflies \
		${XSSCONFDIR}/fireflies.xml

OPTIONS_DEFINE=	SDL
SDL_DESC=	SDL support, needed for running standalone

SDL_USES=		sdl
SDL_USE=		SDL=sdl
SDL_CONFIGURE_OFF=	ac_cv_prog_SDL_CONF=""

XSSHACKSDIR=	bin/xscreensaver-hacks
XSSCONFDIR=	share/xscreensaver/config

# The bundled libgfx has an "automagic" dependency on FLTK that can't be
# overridden, therefore forcefully disable FLTK after configure.
post-configure:
		@${REINPLACE_CMD} -E '/(^|HAVE_)FLTK/d' \
			${WRKSRC}/libgfx/include/gfx/config.h \
			${WRKSRC}/libgfx/gfx-config

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${XSSHACKSDIR}/fireflies

.include <bsd.port.mk>
