# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	e16
PORTVERSION=	1.0.20
PORTREVISION=	0
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	SF/enlightenment/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enlightenment DR16 window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS NLS PANGO SOUND
OPTIONS_SUB=		yes
SOUND_LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
			libsndfile.so:audio/libsndfile
SOUND_CONFIGURE_ON=	--enable-sound=pulseaudio \
			--with-sndldr=sndfile
SOUND_CONFIGURE_OFF=	--disable-sound \
			--with-sndldr=none
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
PANGO_USE=		GNOME=pango
PANGO_CONFIGURE_ENABLE=	pango
DOCS_CONFIGURE_ON=	--enable-docs=yes
DOCS_CONFIGURE_OFF=	--enable-docs=no

USES=		autoreconf gmake iconv libtool gnome perl5 pkgconfig \
		shebangfix xorg

USE_XORG=	ice sm xorgproto x11 xbitmaps \
		xcomposite xdamage xext xfixes xft xinerama xrandr xrender \
		xxf86vm
SHEBANG_FILES=	scripts/e_gen_menu
CFLAGS+=	-Wno-unused-parameter -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-rpath --enable-mans SHELL=/bin/sh

post-patch:
	${REINPLACE_CMD} -e 's|$$(USER)|${SHAREOWN}:${SHAREGRP}|g' \
	    ${WRKSRC}/themes/Makefile.am ${WRKSRC}/themes/Makefile.in
	${REINPLACE_CMD} -e '/dl, dlopen/d' ${WRKSRC}/configure.ac

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/s|docs ||' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
