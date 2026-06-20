DISTVERSION=	304.137
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	11

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-304

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

PLIST_FILES=	${EXTENSIONSDIR}/libglx.so \
		${EXTENSIONSDIR}/libglx.so.1

SLAVE_POST_PATCH=	slave-post-patch

slave-post-patch:
# Adjust installation path of a conflicting file (shared between
# nvidia-driver and xorg-server) to ease package manager work
	${REINPLACE_CMD} -e '/LIBDIR/s:xorg/modules/extensions:&/.nvidia:' \
		${WRKSRC}/x11/extension/Makefile

.include "${MASTERDIR}/Makefile"
