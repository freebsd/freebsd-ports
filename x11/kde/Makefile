PORTNAME=	kde
PORTVERSION=	${KDE_PLASMA_VERSION}.${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma Desktop and KDE Applications (meta port)
WWW=		https://www.kde.org

RUN_DEPENDS=	kde-baseapps>=${KDE_APPLICATIONS_VERSION}:x11/kde-baseapps

USES=		kde:6 metaport qt:6
USE_KDE=	${_USE_PLASMA_ALL:Nbreeze-gtk:Nkde-gtk-config:Noxygen:Noxygen-sounds}

# The official VLC backend can be used, but vlc port still uses Qt5 for GUI.
OPTIONS_DEFAULT=	MPV
OPTIONS_MULTI=		PHONON
OPTIONS_MULTI_PHONON=	MPV VLC

PHONON_DESC=	Phonon multimedia backend

MPV_DESC=	mpv backend
MPV_USE=	KDE=phonon-mpv

VLC_DESC=	VLC backend (depends on Qt5 packages)
VLC_USE=	KDE=phonon-vlc

.include <bsd.port.mk>
