PORTNAME=	kde
PORTVERSION=	${KDE_PLASMA_VERSION}.${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma Desktop and Applications (meta port)
WWW=		https://www.kde.org

RUN_DEPENDS=	kde-baseapps>=${KDE_APPLICATIONS_VERSION}:x11/kde-baseapps \
		plasma6-plasma>=${KDE_PLASMA_VERSION}:x11/plasma6-plasma

USES=		kde:6 metaport qt:6

# The official VLC backend can be used, but vlc port still uses Qt5 for GUI.
OPTIONS_DEFAULT=	MPV
OPTIONS_MULTI=	PHONON
OPTIONS_MULTI_PHONON=	MPV VLC

PHONON_DESC=	Phonon multimedia backend

MPV_DESC=	mpv backend
MPV_USE=	KDE=phonon-mpv

VLC_DESC=	VLC backend (depends on Qt5 packages)
VLC_USE=	KDE=phonon-vlc

.include <bsd.port.mk>
