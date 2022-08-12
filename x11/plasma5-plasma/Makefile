PORTNAME=	plasma
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	plasma5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE5 plasma meta port

LICENSE=	LGPL20

USES=		kde:5 metaport qt:5
# remove:
#   * bluedevil we do not have bluez at all
#   * plasma-pa no plasma-pa (pulseaudio) by default
USE_KDE=	${_USE_PLASMA_ALL:Nplasma-pa}

OPTIONS_DEFINE=	PHONON PULSEAUDIO
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

# Different from PHONON, because this is about the output plugins
PHONON_DESC=	Include phonon-gstreamer, for sound output

PHONON_RUN_DEPENDS=	${QT_PLUGINDIR}/phonon4qt5_backend/phonon_gstreamer.so:multimedia/phonon-gstreamer
PULSEAUDIO_USE=	KDE=plasma-pa_run

.include <bsd.port.mk>
