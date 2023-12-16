PORTNAME=	kgamma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Adjust gamma settings

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons doctools i18n \
		kcmutils kdeclarative widgetsaddons \
		ecm:build
USE_QT=		base
USE_XORG=	ice sm x11 xext xxf86vm

.include <bsd.port.mk>
