# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	2.0.3
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>2:x11-toolkits/py-gtk2@${FLAVOR} \
		${PYNUMPY}
LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lz4>=0.7.0_1:archivers/py-lz4@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rencode>1:converters/py-rencode@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=3.0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.0:graphics/py-PyOpenGL@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL-accelerate>=3.1.0:graphics/py-PyOpenGL-accelerate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${FLAVOR} \
		ssh-askpass:security/openssh-askpass \
		${PYTHON_PKGNAMEPREFIX}cryptography>1:security/py-cryptography@${FLAVOR} \
		setxkbmap:x11/setxkbmap \
		xauth:x11/xauth \
		xkbcomp:x11/xkbcomp \
		${LOCALBASE}/share/X11/xkb/rules/base:x11/xkeyboard-config \
		Xvfb:x11-servers/xorg-vfbserver \
		${PYTHON_PKGNAMEPREFIX}gtk2>2:x11-toolkits/py-gtk2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtkglext>1:x11-toolkits/py-gtkglext@${FLAVOR} \
		${PYNUMPY}

USES=		desktop-file-utils fortran gettext-runtime pkgconfig python:2.7 shared-mime-info shebangfix tar:xz
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_PYTHON=	distutils cython
USE_XORG=	x11 xcomposite xdamage xext xfixes xkbfile xrandr xtst
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHON_VER=${PYTHON_VER}
SHEBANG_FILES=	cups/xpraforwarder

OPTIONS_DEFINE=		AVAHI AVCODEC CUPS FFMPEG GSTREAMER HTML5 LIBYUV SWSCALE VPX WEBCAM X264 X265
OPTIONS_DEFAULT=	AVAHI AVCODEC CUPS FFMPEG GSTREAMER HTML5 LIBYUV SWSCALE VPX X264
OPTIONS_SUB=		yes

AVCODEC_DESC=	Enable avcodec2 (FFmpeg) decoder
CUPS_DESC=	Enable CUPS for printer forwarding
FFMPEG_DESC=	Enable FFmpeg encoder
GSTREAMER_DESC=	Enable GStreamer for sound forwarding
HTML5_DESC=	Install HTML5 client interface
LIBYUV_DESC=	Enable libyuv CSC module (fastest)
SWSCALE_DESC=	Enable swscale (FFmpeg) CSC module
VPX_DESC=	Enable VP8 and VP9 codec
WEBCAM_DESC=	Enable webcam forwarding (client only)
X264_DESC=	Enable X264 encoder
X265_DESC=	Enable X265 encoder (slow)

AVAHI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}avahi>0:net/py-avahi@${FLAVOR}
AVAHI_VARS=		XPRA_OPTIONS+=mdns
AVCODEC_VARS=		XPRA_OPTIONS+=dec_avcodec2
CUPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycups>1:print/py-pycups@${FLAVOR}
CUPS_VARS=		XPRA_OPTIONS+=printing
FFMPEG_VARS=		XPRA_OPTIONS+=enc_ffmpeg
GSTREAMER_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}gstreamer1>1:multimedia/py-gstreamer1@${FLAVOR}
GSTREAMER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>1:multimedia/py-gstreamer1@${FLAVOR}
GSTREAMER_USE=		GSTREAMER1=flac,lame,mpg123,ogg,opus,vorbis,wavpack
GSTREAMER_VARS=		XPRA_OPTIONS+=sound
HTML5_VARS=		XPRA_OPTIONS+=html5
LIBYUV_LIB_DEPENDS=	libyuv.so:graphics/libyuv
LIBYUV_VARS=		XPRA_OPTIONS+=csc_libyuv
SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_VARS=		XPRA_OPTIONS+=csc_swscale
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_VARS=		XPRA_OPTIONS+=vpx
WEBCAM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opencv>2:graphics/py-opencv@${FLAVOR}
WEBCAM_VARS=		XPRA_OPTIONS+=webcam
X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X264_VARS=		XPRA_OPTIONS+=enc_x264
X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_VARS=		XPRA_OPTIONS+=enc_x265

PYDISTUTILS_PKGNAME=	xpra_all
XPRA_OPTIONS_ALL=	csc_libyuv csc_swscale
XPRA_OPTIONS_ALL+=	dec_avcodec2 enc_ffmpeg enc_x264 enc_x265
XPRA_OPTIONS_ALL+=	html5 mdns sound printing vpx webcam
XPRA_OPTIONS_ALL+=	${XPRA_OPTIONS_DISABLED}
XPRA_OPTIONS_DISABLED=	Xdummy Xdummy_wrapper minify nvenc7

.include <bsd.port.options.mk>

.for opt in ${XPRA_OPTIONS_ALL}
.if empty(XPRA_OPTIONS:M${opt})
PYDISTUTILS_ARGS+=	--without-${opt}
.else
PYDISTUTILS_ARGS+=	--with-${opt}
.endif
.endfor

.if ${PORT_OPTIONS:MAVCODEC} || ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg
.endif

.include <bsd.port.pre.mk>

PYDISTUTILS_BUILDARGS+=		${PYDISTUTILS_ARGS}
PYDISTUTILS_CONFIGUREARGS+=	${PYDISTUTILS_ARGS}
PYDISTUTILS_INSTALLARGS+=	${PYDISTUTILS_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%GCC_RUNTIME%%|${LOCALBASE}/lib/gcc${_GCC_VER}|' \
	    ${WRKSRC}/scripts/xpra ${WRKSRC}/scripts/xpra_launcher
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
	    ${WRKSRC}/xpra/platform/pycups_printing.py
	@${REINPLACE_CMD} -e 's|/usr/sbin|${LOCALBASE}/sbin|' \
	    ${WRKSRC}/etc/xpra/conf.d/16_printing.conf.in

post-install:
	@${MV} ${STAGEDIR}${ETCDIR}/xorg.conf \
	    ${STAGEDIR}${ETCDIR}/xorg.conf.sample
	@${MV} ${STAGEDIR}${ETCDIR}/xpra.conf \
	    ${STAGEDIR}${ETCDIR}/xpra.conf.sample
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name '*.so' \
	    -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
