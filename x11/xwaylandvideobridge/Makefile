PORTNAME=	xwaylandvideobridge
DISTVERSION=	0.4.0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tool to share specific windows to X11 clients
WWW=		https://invent.kde.org/system/xwaylandvideobridge

USES=		cmake kde:5 qt:5 tar:xz xorg
USE_KDE=	coreaddons i18n kpipewire notifications windowsystem \
		ecm:build
USE_QT=		core dbus declarative gui network widgets x11extras \
		buildtools:build qmake:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
