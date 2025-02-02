PORTNAME=	xwaylandvideobridge
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tool to share specific windows to X11 clients
WWW=		https://invent.kde.org/system/xwaylandvideobridge

USES=		cmake compiler:c++20-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	coreaddons i18n kpipewire notifications statusnotifieritem \
		windowsystem \
		ecm:build
USE_QT=		base declarative \
		tools:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
