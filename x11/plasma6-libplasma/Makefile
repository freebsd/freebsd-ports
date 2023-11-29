PORTNAME=	libplasma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Shared libraries for Plasma Desktop

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols

USES=		cmake gettext kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	activities archive config configwidgets coreaddons globalaccel \
		guiaddons i18n iconthemes kcmutils kio kirigami2 notifications \
		package plasma-wayland-protocols svg windowsystem \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
