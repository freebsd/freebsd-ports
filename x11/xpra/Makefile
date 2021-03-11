# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	4.1.1
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Persistent remote applications for X

LICENSE=	GPLv2

BUILD_DEPENDS=	brotli:archivers/brotli \
		pandoc:textproc/hs-pandoc
LIB_DEPENDS=	libwebp.so:graphics/webp
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}bencode.py>1:converters/py-bencode.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0.7.0_1:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL-accelerate>=3.1.0:graphics/py-PyOpenGL-accelerate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rencode>1:converters/py-rencode@${PY_FLAVOR} \
		setxkbmap:x11/setxkbmap \
		ssh-askpass:security/openssh-askpass \
		xauth:x11/xauth \
		xkbcomp:x11/xkbcomp \
		Xvfb:x11-servers/xorg-vfbserver

USES=		desktop-file-utils gettext-runtime gnome pkgconfig \
		python:3.6+ shared-mime-info shebangfix tar:xz xorg

USE_GNOME=	cairo gdkpixbuf2 gtk30 pygobject3
USE_PYTHON=	cython distutils noflavors
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xkbfile xrandr xtst
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYTHON_VER=${PYTHON_VER}
SHEBANG_FILES=	fs/lib/cups/xpraforwarder fs/bin/auth_dialog fs/bin/xdg-open \
		fs/bin/xpra_udev_product_version fs/bin/gnome-open \
		fs/bin/gvfs-open
SHEBANG_LANG=	sh
sh_OLD_CMD=	/usr/bin/sh
sh_CMD=		/bin/sh
MAKE_ENV=	XPRA_USE_PROCESS_POLLING=1

OPTIONS_DEFINE=		AVAHI AVCODEC CUPS FFMPEG GSTREAMER LIBYUV SWSCALE VPX \
			WEBCAM X264 X265
OPTIONS_DEFAULT=	AVAHI AVCODEC CUPS FFMPEG GSTREAMER LIBYUV SWSCALE VPX \
			X264 X265
OPTIONS_SUB=		yes

AVCODEC_DESC=	Enable avcodec2 (FFmpeg) decoder
CUPS_DESC=	Enable CUPS for printer forwarding
FFMPEG_DESC=	Enable FFmpeg encoder
GSTREAMER_DESC=	Enable GStreamer for sound forwarding
LIBYUV_DESC=	Enable libyuv CSC module (fastest)
SWSCALE_DESC=	Enable swscale (FFmpeg) CSC module
VPX_DESC=	Enable VP8 and VP9 codec
WEBCAM_DESC=	Enable webcam forwarding (client only)
X264_DESC=	Enable X264 encoder
X265_DESC=	Enable X265 encoder

AVAHI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}avahi>0:net/py-avahi@${PY_FLAVOR}
AVAHI_VARS=			XPRA_OPTIONS+=mdns
AVCODEC_VARS=			XPRA_OPTIONS+=dec_avcodec2
CUPS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pycups>1:print/py-pycups@${PY_FLAVOR}
CUPS_VARS=			XPRA_OPTIONS+=printing
FFMPEG_VARS=			XPRA_OPTIONS+=enc_ffmpeg
GSTREAMER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>1:multimedia/py-gstreamer1@${PY_FLAVOR}
GSTREAMER_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gstreamer1>1:multimedia/py-gstreamer1@${PY_FLAVOR} \
				gstreamer1-plugins-pulse>1:audio/gstreamer1-plugins-pulse
GSTREAMER_USE=			GSTREAMER1=flac,lame,mpg123,ogg,opus,vorbis,wavpack
GSTREAMER_VARS=			XPRA_OPTIONS+=sound
LIBYUV_LIB_DEPENDS=		libyuv.so:graphics/libyuv
LIBYUV_VARS=			XPRA_OPTIONS+=csc_libyuv
SWSCALE_LIB_DEPENDS=		libswscale.so:multimedia/ffmpeg
SWSCALE_VARS=			XPRA_OPTIONS+=csc_swscale
VPX_LIB_DEPENDS=		libvpx.so:multimedia/libvpx
VPX_VARS=			XPRA_OPTIONS+=vpx
WEBCAM_RUN_DEPENDS=		opencv>2:graphics/opencv
WEBCAM_VARS=			XPRA_OPTIONS+=webcam
X264_LIB_DEPENDS=		libx264.so:multimedia/libx264
X264_VARS=			XPRA_OPTIONS+=enc_x264
X265_LIB_DEPENDS=		libx265.so:multimedia/x265
X265_VARS=			XPRA_OPTIONS+=enc_x265

PYDISTUTILS_PKGNAME=	xpra_all
XPRA_OPTIONS_ALL+=	${XPRA_OPTIONS_DISABLED} csc_libyuv csc_swscale \
			dec_avcodec2 enc_ffmpeg enc_x264 enc_x265 \
			mdns printing sound vpx webcam
XPRA_OPTIONS_DISABLED=	netdev service uinput Xdummy Xdummy_wrapper

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

PYDISTUTILS_BUILDARGS+=	${PYDISTUTILS_ARGS}
PYDISTUTILS_CONFIGUREARGS+=	${PYDISTUTILS_ARGS}
PYDISTUTILS_INSTALLARGS+=	${PYDISTUTILS_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
	    ${WRKSRC}/xpra/platform/pycups_printing.py
	@${REINPLACE_CMD} -e 's|/usr/sbin|${LOCALBASE}/sbin|' \
	    ${WRKSRC}/fs/etc/xpra/conf.d/16_printing.conf.in

post-install:
	@${MV} ${STAGEDIR}${ETCDIR}/xorg.conf \
	    ${STAGEDIR}${ETCDIR}/xorg.conf.sample
	@${MV} ${STAGEDIR}${ETCDIR}/xpra.conf \
	    ${STAGEDIR}${ETCDIR}/xpra.conf.sample
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name '*.so' \
	    -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
