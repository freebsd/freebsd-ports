DISTVERSION=	304.137
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	11

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-304

MAKE_ENV=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}

PLIST_FILES=	${EXTENSIONSDIR}/libglx.so \
		${EXTENSIONSDIR}/libglx.so.1

SLAVE_POST_PATCH=	slave-post-patch
SLAVE_POST_INSTALL=	slave-post-install

slave-post-patch:
# Adjust installation path of a conflicting file (shared between
# nvidia-driver and xorg-server) to ease package manager work
	${REINPLACE_CMD} -e '/LIBDIR/s:xorg/modules/extensions:&/.nvidia:' \
		${WRKSRC}/x11/extension/Makefile

slave-post-install:
	${REINPLACE_CMD} -e '/libnvidia-glvkspirv\.so/d ; \
		/nvidia_icd\.json/d ; /nvidia_layers\.json/d' ${TMPPLIST}
	${REINPLACE_CMD} -E '/lib(nvidia-)?(EGL|eglcore|GLESv|glsi)/d' \
		${TMPPLIST}
	${REINPLACE_CMD} -E '/(lib)?nvidia-(debugdump|smi|ml)/d' ${TMPPLIST}
	${REINPLACE_CMD} -E '/lib(EGL|GLESv[12].*)_nvidia/d ; \
		/lib(GLX|GLdispatch|OpenGL)/d ; \
		/extensions\/libglxserver_nvidia\.so/d ; \
		/10_nvidia\.json/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/libnvidia-egl-wayland\.so/d ; \
		/10_nvidia_wayland\.json/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/lib32\//d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/libnvidia-egl-gbm\.so/d ; \
		/15_nvidia_gbm\.json/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/libnvidia-allocator\.so/d ; \
		/nvidia-drm_gbm\.so/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/libnvidia-gpucomp\.so/d' ${TMPPLIST}
# Rename some libraries and install a libmap file to resolve conflict with
# Mesa libraries.
	${LN} -sf libGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so.1
	${RM} ${STAGEDIR}${PREFIX}/lib/libGL.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/libmap.d/
	${INSTALL_DATA} ${WRKDIR}/nvidia.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/

.include "${MASTERDIR}/Makefile"
