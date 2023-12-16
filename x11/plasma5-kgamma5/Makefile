PORTNAME=	kgamma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 display gamma settings
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons i18n init service \
		widgetsaddons \
		doctools:build ecm:build
USE_QT=		core gui widgets xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext xxf86vm

.include <bsd.port.mk>
