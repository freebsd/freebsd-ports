PORTNAME=	kde6
DISTVERSION=	${KDE_PLASMA_VERSION}.${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma Desktop and Applications (current)
WWW=		https://www.kde.org

RUN_DEPENDS=	plasma6-plasma>0:x11/plasma6-plasma \
		kf6-frameworks>0:x11/kf6-frameworks \
		kate-devel>0:editors/kate-devel \
		dolphin-devel>0:x11-fm/dolphin-devel \
		konsole-devel>0:x11/konsole-devel \
		gwenview-devel>0:graphics/gwenview-devel

USES=		kde:6 metaport qt:6
USE_QT=		# empty

.include <bsd.port.mk>
