PORTNAME=	xlibre-minimal
PORTVERSION=	1.0
CATEGORIES=	x11 x11-servers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre + X.Org minimal distribution metaport
WWW=		https://github.com/X11Libre/xserver/ \
		https://www.x.org/

USES=		metaport

.include "../../x11-servers/xlibre-server/Makefile.version"
MODULEDIR=	${LOCALBASE}/lib/xorg/modules/xlibre-${XLIBRE_MJR_VER}/
VIDEODIR=	${MODULEDIR}/drivers
INPUTDIR=	${MODULEDIR}/input

.include <bsd.port.options.mk>

VIDEO_DRIVER?=	vesa

RUN_DEPENDS+=	${LOCALBASE}/bin/Xorg:x11-servers/xlibre-server \
		${LOCALBASE}/bin/xinit:x11/xinit \
		${LOCALBASE}/bin/xauth:x11/xauth \
		${INPUTDIR}/libinput_drv.so:x11-drivers/xlibre-xf86-input-libinput

.if ${VIDEO_DRIVER} == "nvidia"
RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/drivers/nvidia_drv.so:x11/nvidia-driver@xlibre
.elif ${VIDEO_DRIVER} == "intel"
RUN_DEPENDS+=	${LOCALBASE}/lib/dri/i965_drv_video.so:multimedia/libva-intel-driver
RUN_DEPENDS+=	${VIDEODIR}/${VIDEO_DRIVER}_drv.so:x11-drivers/xlibre-xf86-video-${VIDEO_DRIVER}
.else
RUN_DEPENDS+=	${VIDEODIR}/${VIDEO_DRIVER}_drv.so:x11-drivers/xlibre-xf86-video-${VIDEO_DRIVER}
.endif

.include <bsd.port.mk>
