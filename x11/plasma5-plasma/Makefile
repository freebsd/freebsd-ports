# $FreeBSD$

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
#   * bluedevil as we do have bluez
#   * plasma-pa don't depend on plamsa-pa by default
#   * breeze-kde4 don't pull in qt4 bits
USE_KDE=	${_USE_PLASMA_ALL:Nplasma-pa:Nbreeze-kde4}

OPTIONS_DEFINE=	PHONON PULSEAUDIO
OPTIONS_DEFAULT=	PHONON

# Different from PHONON, because this is about the output plugins
PHONON_DESC=	Include phonon-gstreamer, for sound output

PHONON_RUN_DEPENDS=	${QT_PLUGINDIR}/phonon4qt5_backend/phonon_gstreamer.so:multimedia/phonon-gstreamer@qt5
PULSEAUDIO_USE=	KDE=plasma-pa_run

.include <bsd.port.mk>
