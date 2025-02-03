PORTNAME=	plasma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	plasma6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE6 plasma meta port
WWW=		https://www.kde.org/plasma-desktop

USES=		kde:6 metaport qt:6
# remove:
#   * plasma-pa no plasma-pa (pulseaudio) by default
USE_KDE=	${_USE_PLASMA_ALL:Nplasma-pa}

OPTIONS_DEFINE=		PULSEAUDIO QT5
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

PULSEAUDIO_USE=		KDE=plasma-pa:run
QT5_DESC=		Install Plasma 6 integration plugins for Qt5 applications
QT5_RUN_DEPENDS=	plasma6-plasma-integration-qt5>0:x11/plasma6-plasma-integration@qt5

.include <bsd.port.mk>
