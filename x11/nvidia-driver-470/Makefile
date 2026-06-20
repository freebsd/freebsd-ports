DISTVERSION=	470.256.02
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	2

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-470

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

SLAVE_POST_INSTALL=	slave-post-install

slave-post-install:
	${REINPLACE_CMD} -e '/libnvidia-egl-gbm\.so/d ; \
		/15_nvidia_gbm\.json/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/libnvidia-allocator\.so/d ; \
		/nvidia-drm_gbm\.so/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/libnvidia-gpucomp\.so/d' ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
