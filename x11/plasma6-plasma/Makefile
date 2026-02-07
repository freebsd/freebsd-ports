PORTNAME=	plasma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	plasma6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma 6 Desktop (meta port)
WWW=		https://www.kde.org/plasma-desktop

USES=		kde:6 metaport qt:6
USE_KDE=	${_USE_PLASMA_ALL:Nplasma-pa:Nbreeze-gtk:Nkde-gtk-config}

OPTIONS_DEFINE=		GTK PULSEAUDIO QT5
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

GTK_DESC=		Breeze widget theme for GTK2 and GTK3 applications
GTK_USE=		KDE=breeze-gtk:run,kde-gtk-config:run
PULSEAUDIO_DESC=	Plasma applet for audio volume management
PULSEAUDIO_USE=		KDE=plasma-pa:run
QT5_DESC=		Plasma 6 integration plugins for Qt5 applications
QT5_RUN_DEPENDS=	plasma6-plasma-integration-qt5>0:x11/plasma6-plasma-integration@qt5 \
			plasma6-breeze-qt5>0:x11-themes/plasma6-breeze@qt5

.include <bsd.port.mk>
