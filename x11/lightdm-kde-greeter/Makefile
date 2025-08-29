PORTNAME=	lightdm-kde-greeter
PORTVERSION=	6.0.3
PORTREVISION=	1
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE login screen using the LightDM framework
WWW=		https://invent.kde.org/plasma/lightdm-kde-greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL3

LIB_DEPENDS=	libnm.so:net-mgmt/networkmanager-shim \
		liblightdm-gobject-1.so:x11/lightdm
RUN_DEPENDS=	at-spi2-core>0:accessibility/at-spi2-core

USES=		cmake compiler:c++17-lang gettext gl gnome kde:6 pkgconfig \
		qt:6 tar:xz xorg
USE_GL=		opengl
USE_GNOME=	gtk20
USE_KDE=	auth colorscheme config configwidgets coreaddons i18n \
		iconthemes kcmutils libplasma networkmanagerqt package \
		widgetsaddons \
		ecm:build
USE_QT=		5compat base declarative
USE_XORG=	x11 xcb xext xrandr xrender

KDE_INVENT=	31d29530ad834c1bfb70ed43f9395a549fbace56 plasma

CMAKE_ARGS=	-DGREETER_IMAGES_DIR="${PREFIX}/var/db/${PORTNAME}/images" \
		-DLIGHTDM_CONFIG_DIR=${PREFIX}/etc/lightdm \
		-DDATA_INSTALL_DIR=${PREFIX}/share

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd
	(cd ${STAGEDIR}${PREFIX}/etc/lightdm && ${MV} lightdm-kde-greeter.conf \
		lightdm-kde-greeter.conf.sample)

.include <bsd.port.mk>
