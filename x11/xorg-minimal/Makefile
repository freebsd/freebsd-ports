# $FreeBSD$

PORTNAME=	xorg
PORTVERSION=	7.5.2
CATEGORIES=	x11 x11-servers
MASTER_SITES=	# none
PKGNAMESUFFIX=	-minimal
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	X.Org minimal distribution metaport

NO_BUILD=	yes
NO_MTREE=	yes

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

.if ${VIDEO_DRIVER} == intel && defined(WITH_NEW_XORG)
RUN_DEPENDS+=	${LOCALBASE}/lib/va/i965_drv_video.so:${PORTSDIR}/multimedia/libva-intel-driver
.endif

do-install:

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"
	@${ECHO_MSG} "This port does not ensure things are upgraded; use portmaster if you want to"
	@${ECHO_MSG} "upgrade X.Org. The \"vesa\" driver is installed by default. You can choose a"
	@${ECHO_MSG} "different one by means of the VIDEO_DRIVER parameter. For example:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "        make install VIDEO_DRIVER=intel"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
