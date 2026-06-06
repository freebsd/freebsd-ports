DISTVERSION=	470.256.02
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	2

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-470

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

.include "${MASTERDIR}/Makefile"
