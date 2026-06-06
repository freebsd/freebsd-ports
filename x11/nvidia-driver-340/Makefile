DISTVERSION=	340.108
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	5

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-340

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

PLIST_FILES=	${EXTENSIONSDIR}/libglx.so \
		${EXTENSIONSDIR}/libglx.so.1

.include "${MASTERDIR}/Makefile"
