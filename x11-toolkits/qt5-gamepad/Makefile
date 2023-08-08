PORTNAME=	gamepad
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 Gamepad Module

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		compiler:c++11-lang perl5 qmake:norecursive qt-dist:5,gamepad
USE_PERL5=	build
USE_QT=		core declarative gui buildtools:build

.include <bsd.port.mk>
