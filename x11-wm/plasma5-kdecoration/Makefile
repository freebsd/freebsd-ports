PORTNAME=	kdecoration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-wm kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to create window decorations
WWW=		https://www.kde.org/plasma-desktop

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_LDCONFIG=	yes
USE_KDE=	coreaddons i18n \
		ecm:build
USE_QT=		core gui \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
