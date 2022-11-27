PORTNAME=	cheri-desktop
PORTVERSION=	20221019
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	br@FreeBSD.org
COMMENT=	Meta-port with the CHERI desktop environment.
WWW=		https://cheribsd.org/

USES=		metaport

ONLY_FOR_ARCHS=		aarch64 aarch64c
ONLY_FOR_ARCHS_REASON=	requires GPU support available only on the Morello platform

RUN_DEPENDS=	${LOCALBASE}/bin/dolphin:x11-fm/dolphin
RUN_DEPENDS+=	${LOCALBASE}/bin/eglinfo:graphics/mesa-demos
RUN_DEPENDS+=	${LOCALBASE}/bin/kaccess:x11/plasma5-plasma-desktop
RUN_DEPENDS+=	${LOCALBASE}/bin/kate:editors/kate
RUN_DEPENDS+=	${LOCALBASE}/bin/konsole:x11/konsole
RUN_DEPENDS+=	${LOCALBASE}/bin/kwin_wayland:x11-wm/plasma5-kwin
RUN_DEPENDS+=	${LOCALBASE}/bin/okular:graphics/okular
RUN_DEPENDS+=	${LOCALBASE}/bin/plasmashell:x11/plasma5-plasma-workspace
RUN_DEPENDS+=	${LOCALBASE}/bin/sddm:x11/sddm
RUN_DEPENDS+=	${LOCALBASE}/bin/seatd:sysutils/seatd
RUN_DEPENDS+=	${LOCALBASE}/lib/libEGL.so:graphics/libglvnd
RUN_DEPENDS+=	${LOCALBASE}/lib/libEGL_mesa.so:graphics/mesa-libs
RUN_DEPENDS+=	${LOCALBASE}/lib/libKF5Plasma.so:x11/kf5-plasma-framework
RUN_DEPENDS+=	${LOCALBASE}/lib/libKF5WaylandServer.so:x11/kf5-kwayland
RUN_DEPENDS+=	${LOCALBASE}/lib/libKWaylandServer.so:x11/plasma5-kwayland-server
RUN_DEPENDS+=	${LOCALBASE}/lib/libdrm.so:graphics/libdrm
RUN_DEPENDS+=	${LOCALBASE}/lib/libwayland-server.so:graphics/wayland
RUN_DEPENDS+=	${LOCALBASE}/lib/qt5/plugins/kf5/kwindowsystem/KF5WindowSystemKWaylandPlugin.so:x11/plasma5-kwayland-integration
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/terminus-font/ter-112b.pcf.gz:x11-fonts/terminus-font
RUN_DEPENDS+=	${LOCALBASE}/share/mime/packages/freedesktop.org.xml:misc/shared-mime-info
RUN_DEPENDS+=	${LOCALBASE}/share/wallpapers/Elarun/metadata.desktop:x11-themes/plasma5-plasma-workspace-wallpapers

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == aarch64c
RUN_DEPENDS+=	${LOCALBASE}/lib/dri/panfrost_dri.so:graphics/mesa-dri
.endif

SUB_FILES=	sddm \
		seatd

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${FILESDIR}/cheri-desktop ${STAGEDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/sddm ${STAGEDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/seatd ${STAGEDIR}${PREFIX}/etc/rc.conf.d

.include <bsd.port.mk>
