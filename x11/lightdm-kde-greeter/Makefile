PORTNAME=	lightdm-kde-greeter
PORTVERSION=	6.0.3
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE login screen using the LightDM framework
WWW=		https://invent.kde.org/plasma/lightdm-kde-greeter

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm
RUN_DEPENDS=	at-spi2-core>0:accessibility/at-spi2-core

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL3

USES=		cmake compiler:c++11-lang gettext gnome kde:6 pkgconfig qt:6 \
		tar:xz xorg
USE_KDE=	auth config configwidgets i18n iconthemes kcmutils networkmanagerqt \
		package plasma-workspace \
		ecm:build
USE_GNOME=	gtk20
USE_QT=		base
USE_XORG=	x11

KDE_INVENT=	31d29530ad834c1bfb70ed43f9395a549fbace56 plasma

CMAKE_ARGS=	-DGREETER_IMAGES_DIR="${PREFIX}/var/db/${PORTNAME}/images" \
		-DLIGHTDM_CONFIG_DIR=${PREFIX}/etc/lightdm \
		-DDATA_INSTALL_DIR=${PREFIX}/share

post-stage:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
