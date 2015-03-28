# $FreeBSD$

PORTNAME=	xorg
PORTVERSION=	7.5.2
PORTREVISION=	1
CATEGORIES=	x11 x11-servers
PKGNAMESUFFIX=	-minimal

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X.Org minimal distribution metaport

USES=		metaport
.include <bsd.port.options.mk>

VIDEO_DRIVER?=	vesa

RUN_DEPENDS+=	${LOCALBASE}/bin/Xorg:${PORTSDIR}/x11-servers/xorg-server \
		${LOCALBASE}/lib/xorg/modules/input/mouse_drv.so:${PORTSDIR}/x11-drivers/xf86-input-mouse \
		${LOCALBASE}/lib/xorg/modules/input/kbd_drv.so:${PORTSDIR}/x11-drivers/xf86-input-keyboard \
		${LOCALBASE}/bin/xinit:${PORTSDIR}/x11/xinit \
		${LOCALBASE}/bin/xauth:${PORTSDIR}/x11/xauth
.if ${VIDEO_DRIVER} == "nvidia"
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/nvidia_drv.so:${PORTSDIR}/x11/nvidia-driver
.elif ${VIDEO_DRIVER} == "intel29"
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/intel_drv.so:${PORTSDIR}/x11-drivers/xf86-video-${VIDEO_DRIVER}
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/${VIDEO_DRIVER}_drv.so:${PORTSDIR}/x11-drivers/xf86-video-${VIDEO_DRIVER}
.endif

.if ${VIDEO_DRIVER} == intel
RUN_DEPENDS+=	${LOCALBASE}/lib/va/i965_drv_video.so:${PORTSDIR}/multimedia/libva-intel-driver
.endif

.include <bsd.port.mk>
