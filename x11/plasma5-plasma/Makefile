PORTNAME=	plasma
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	plasma5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE5 plasma meta port
WWW=		https://www.kde.org/plasma-desktop

USES=		kde:5 metaport qt:5
# remove:
#   * bluedevil we do not have bluez at all
#   * plasma-pa no plasma-pa (pulseaudio) by default
USE_KDE=	${_USE_PLASMA_ALL:Nplasma-pa}

OPTIONS_DEFINE=	PHONON PULSEAUDIO
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

# Different from PHONON, because this is about the output plugins
PHONON_DESC=	Include phonon-vlc, for sound output

PHONON_USE=	KDE=phonon-backend:run
PULSEAUDIO_USE=	KDE=plasma-pa:run

.include <bsd.port.mk>
