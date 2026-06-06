DISTVERSION=	390.157
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	1

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-390

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

.include "${MASTERDIR}/Makefile"
