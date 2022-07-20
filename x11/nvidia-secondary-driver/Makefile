PORTNAME=	nvidia-secondary-driver
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	1

MASTERDIR?=	${.CURDIR}/../nvidia-driver

MAINTAINER=	theron.tarigo@gmail.com
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering on secondary device

CONFLICTS_INSTALL=	nvidia-driver

EXTENSIONSDIR=	lib/xorg/modules-NVIDIA/extensions

LIBGLDIR=	lib/libGL-NVIDIA

SUB_FILES=	pkg-message

.include "${MASTERDIR}/Makefile"
