# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>

PORTNAME=	e16
PORTVERSION=	1.0.23
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

USES=		autoreconf gettext-tools gmake iconv libtool gnome perl5 \
		pkgconfig shebangfix xorg

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS NLS PANGO
OPTIONS_RADIO=		SOUND SOUNDLOADER
OPTIONS_RADIO_SOUND=	PULSEAUDIO SNDIO
OPTIONS_RADIO_SOUNDLOADER=	SNDFILE AUDIOFILE
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	PULSEAUDIO SNDFILE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=--enable-sound=pulseaudio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=	--enable-sound=sndio
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ON=	--with-sndldr=sndfile
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
AUDIOFILE_CONFIGURE_ON=	--with-sndldr=audiofile
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
PANGO_USE=		GNOME=pango
PANGO_CONFIGURE_ENABLE=	pango
DOCS_CONFIGURE_ON=	--enable-docs=yes
DOCS_CONFIGURE_OFF=	--enable-docs=no

.include <bsd.port.options.mk>

# Double check SOUND and SOUNDLOADER
E16_SOUND=	${PORT_OPTIONS:MPULSEAUDIO}${PORT_OPTIONS:MSNDIO}
E16_SNDLDR=	${PORT_OPTIONS:MSNDFILE}${PORT_OPTIONS:MAUDIOFILE}
.if !empty(E16_SOUND) && empty(E16_SNDLDR)
IGNORE=	sound support requires a sound loader
.endif
.if empty(E16_SOUND) && !empty(E16_SNDLDR)
IGNORE=	sound loader only makes sense with sound support
.endif

USE_XORG=	ice sm xorgproto x11 xbitmaps xcomposite xdamage xext xfixes \
		xft xinerama xrandr xrender xxf86vm
SHEBANG_FILES=	scripts/e_gen_menu
CFLAGS+=	-Wno-unused-parameter -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-dependency-tracking  --disable-rpath \
		--enable-mans SHELL=/bin/sh

.if empty(E16_SOUND) && empty(E16_SNDLDR)
CONFIGURE_ARGS+=--enable-sound=no --with-sndldr=none
.endif

post-patch:
	${REINPLACE_CMD} -e 's|$$(USER)|${SHAREOWN}:${SHAREGRP}|g' \
	    ${WRKSRC}/themes/Makefile.am ${WRKSRC}/themes/Makefile.in
	${REINPLACE_CMD} -e '/dl, dlopen/d' ${WRKSRC}/configure.ac

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/s|docs ||' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
