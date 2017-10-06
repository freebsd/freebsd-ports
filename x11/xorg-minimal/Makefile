# $FreeBSD$

PORTNAME=	xorg
PORTVERSION=	7.5.2
PORTREVISION=	1
CATEGORIES=	x11 x11-servers
PKGNAMESUFFIX=	-minimal

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X.Org minimal distribution metaport

USES=		metaport

RUN_DEPENDS+=	${LOCALBASE}/bin/Xorg:x11-servers/xorg-server \
		${LOCALBASE}/lib/xorg/modules/input/mouse_drv.so:x11-drivers/xf86-input-mouse \
		${LOCALBASE}/lib/xorg/modules/input/kbd_drv.so:x11-drivers/xf86-input-keyboard \
		${LOCALBASE}/bin/xinit:x11/xinit \
		${LOCALBASE}/bin/xauth:x11/xauth

OPTIONS_DEFINE=	VIDEO_DRIVER_VESA VIDEO_DRIVER_NVIDIA VIDEO_DRIVER_INTEL VIDEO_DRIVER_SCFB
OPTIONS_DEFAULT=	VIDEO_DRIVER_VESA

VIDEO_DRIVER_VESA_DESC=	VESA video driver
VIDEO_DRIVER_NVIDIA_DESC=	Nvidia video driver
VIDEO_DRIVER_INTEL_DESC=	Intel video driver
VIDEO_DRIVER_SCFB_DESC=	Framebuffer video driver

VIDEO_DRIVER_NVIDIA_RUN_DEPENDS=	${LOCALBASE}/lib/xorg/modules/drivers/nvidia_drv.so:x11/nvidia-driver

VIDEO_DRIVER_INTEL_RUN_DEPENDS=	${LOCALBASE}/lib/xorg/modules/drivers/intel_drv.so:x11-drivers/xf86-video-intel \
			${LOCALBASE}/lib/va/i965_drv_video.so:multimedia/libva-intel-driver

VIDEO_DRIVER_SCFB_RUN_DEPENDS=	${LOCALBASE}lib/xorg/modules/drivers/scfb_drv.so:x11-drivers/xf86-video-scfb

.include <bsd.port.mk>
