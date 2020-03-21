# $FreeBSD$

PORTNAME=	xorg
PORTVERSION=	7.5.2
PORTREVISION=	3
CATEGORIES=	x11 x11-servers
PKGNAMESUFFIX=	-minimal

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org minimal distribution metaport

USES=		metaport
.include <bsd.port.options.mk>

VIDEO_DRIVER?=	vesa

RUN_DEPENDS+=	${LOCALBASE}/bin/Xorg:x11-servers/xorg-server \
		${LOCALBASE}/bin/xinit:x11/xinit \
		${LOCALBASE}/bin/xauth:x11/xauth

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/input/mouse_drv.so:x11-drivers/xf86-input-mouse
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/input/kbd_drv.so:x11-drivers/xf86-input-keyboard
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/input/libinput_drv.so:x11-drivers/xf86-input-libinput
.endif

.if ${VIDEO_DRIVER} == "nvidia"
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/nvidia_drv.so:x11/nvidia-driver
.elif ${VIDEO_DRIVER} == "intel"
RUN_DEPENDS+=	${LOCALBASE}/lib/dri/i965_drv_video.so:multimedia/libva-intel-driver
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/${VIDEO_DRIVER}_drv.so:x11-drivers/xf86-video-${VIDEO_DRIVER}
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/${VIDEO_DRIVER}_drv.so:x11-drivers/xf86-video-${VIDEO_DRIVER}
.endif

.include <bsd.port.mk>
