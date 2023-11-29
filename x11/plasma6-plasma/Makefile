PORTNAME=	plasma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	plasma6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE6 plasma meta port
WWW=		https://www.kde.org/plasma-desktop

USES=		kde:6 metaport qt:6
# remove:
#   * bluedevil we do not have bluez at all
#   * plasma-pa no plasma-pa (pulseaudio) by default
USE_KDE=	 \
		 ${_USE_PLASMA_ALL:Nplasma-pa:Nhotkeys:Nksysguard:Nkwayland-integration:Ndiscover}

OPTIONS_DEFINE=		PULSEAUDIO
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

PULSEAUDIO_USE=		KDE=plasma-pa:run

.include <bsd.port.mk>
