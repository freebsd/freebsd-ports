DISTVERSION=	304.137
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	11

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-304

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

PLIST_FILES=	${EXTENSIONSDIR}/libglx.so \
		${EXTENSIONSDIR}/libglx.so.1

.include "${MASTERDIR}/Makefile"
