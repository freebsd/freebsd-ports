PORTNAME=	xpra
PORTVERSION=	6.3.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://xpra.org/src/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Persistent remote applications for X
WWW=		https://xpra.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libbrotlidec.so:archivers/brotli \
		libdrm.so:graphics/libdrm \
		libharfbuzz.so:print/harfbuzz \
		liblz4.so:archivers/liblz4 \
		libopenh264.so:multimedia/openh264 \
		libwebp.so:graphics/webp \
		libx264.so:multimedia/libx264 \
		libxxhash.so:devel/xxhash \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}bencode.py>1:converters/py-bencode.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0.7.0_1:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL-accelerate>=3.1.0:graphics/py-PyOpenGL-accelerate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rencode>1:converters/py-rencode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		setxkbmap:x11/setxkbmap \
		ssh-askpass:security/openssh-askpass \
		xauth:x11/xauth \
		xkbcomp:x11/xkbcomp \
		Xvfb:x11-servers/xorg-server@xvfb

USES=		desktop-file-utils gettext-runtime gnome localbase pkgconfig \
		python shared-mime-info shebangfix tar:xz xorg

USE_GNOME=	cairo gdkpixbuf gtk30 pygobject3
USE_PYTHON=	cryptography cython3 distutils noflavors
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xkbfile xrandr xres xtst
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYTHON_VER=${PYTHON_VER}
SHEBANG_FILES=	fs/lib/cups/backend/xpraforwarder fs/libexec/xpra/auth_dialog \
		fs/libexec/xpra/gnome-open fs/libexec/xpra/gvfs-open \
		fs/libexec/xpra/xdg-open fs/libexec/xpra/xpra_signal_listener \
		fs/libexec/xpra/xpra_udev_product_version

OPTIONS_DEFINE=		AVAHI CUPS DOCS GSTREAMER LIBYUV \
			WEBCAM
OPTIONS_DEFAULT=	AVAHI CUPS GSTREAMER
OPTIONS_SUB=		yes

AVCODEC_DESC=	Enable avcodec2 (FFmpeg) decoder
CUPS_DESC=	Enable CUPS for printer forwarding
FFMPEG_DESC=	Enable FFmpeg encoder
GSTREAMER_DESC=	Enable GStreamer for sound forwarding
LIBYUV_DESC=	Enable libyuv CSC module (fastest)
WEBCAM_DESC=	Enable webcam forwarding (client only)

AVAHI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}avahi>0:net/py-avahi@${PY_FLAVOR}
AVAHI_VARS=			XPRA_OPTIONS+=mdns
CUPS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pycups>1:print/py-pycups@${PY_FLAVOR}
CUPS_VARS=			XPRA_OPTIONS+=printing
GSTREAMER_USES=			gstreamer
GSTREAMER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>1:multimedia/py-gstreamer1@${PY_FLAVOR}
GSTREAMER_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gstreamer1>1:multimedia/py-gstreamer1@${PY_FLAVOR}
GSTREAMER_USE=			GSTREAMER=flac,lame,mpg123,ogg,opus,pulse,vorbis,wavpack
GSTREAMER_VARS=			XPRA_OPTIONS+=gstreamer
LIBYUV_LIB_DEPENDS=		libyuv.so:graphics/libyuv
LIBYUV_VARS=			XPRA_OPTIONS+=csc_libyuv
WEBCAM_RUN_DEPENDS=		opencv>2:graphics/opencv
WEBCAM_VARS=			XPRA_OPTIONS+=webcam

PYDISTUTILS_PKGNAME=	xpra_all
XPRA_OPTIONS_ALL+=	${XPRA_OPTIONS_DISABLED} csc_libyuv \
			enc_x264 \
			mdns printing vpx webcam
XPRA_OPTIONS=		dec_avcodec2 enc_ffmpeg enc_x264
XPRA_OPTIONS_DISABLED=	pam strict uinput vpx Xdummy Xdummy_wrapper

.include <bsd.port.options.mk>

.for opt in ${XPRA_OPTIONS_ALL}
.if empty(XPRA_OPTIONS:M${opt})
PYDISTUTILS_ARGS+=	--without-${opt}
.else
PYDISTUTILS_ARGS+=	--with-${opt}
.endif
.endfor

.include <bsd.port.pre.mk>

PYDISTUTILS_BUILDARGS+=	${PYDISTUTILS_ARGS}
PYDISTUTILS_CONFIGUREARGS+=	${PYDISTUTILS_ARGS}
PYDISTUTILS_INSTALLARGS+=	${PYDISTUTILS_ARGS}
#MAKE_ENV=	pkgdir=${STAGEDIR}${PREFIX}/

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
	    ${WRKSRC}/xpra/platform/pycups_printing.py
	@${REINPLACE_CMD} -e 's|/usr/sbin|${LOCALBASE}/sbin|' \
	    ${WRKSRC}/fs/etc/xpra/conf.d/16_printing.conf.in

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} -r ${STAGEDIR}/etc ${STAGEDIR}${PREFIX} && ${RM} -r ${STAGEDIR}/etc
	${MV} ${STAGEDIR}${ETCDIR}/xorg.conf \
	    ${STAGEDIR}${ETCDIR}/xorg.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/xpra.conf \
	    ${STAGEDIR}${ETCDIR}/xpra.conf.sample
	${CP} -r ${STAGEDIR}${PREFIX}/etc/dbus-1 ${STAGEDIR}${PREFIX}/share && ${RM} -r ${STAGEDIR}${PREFIX}/dbus-1
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name '*.so' \
	    -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
