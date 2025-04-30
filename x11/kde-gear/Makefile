PORTNAME=	kde-gear
PORTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Gear distribution (meta port)
WWW=		https://apps.kde.org/

USES=		kde:6 metaport qt:6
USE_QT=		# empty

OPTIONS_DEFINE=	KDEADMIN KDEEDU KDEGAMES KDEGRAPHICS KDEMULTIMEDIA KDENETWORK \
		KDEPIM KDEUTILS
OPTIONS_DEFAULT=${OPTIONS_DEFINE}
OPTIONS_EXCLUDE_FreeBSD_13=	KDEPIM # OpenSSL 1.1.x is not supported

KDEADMIN_DESC=		Administration utilities
KDEADMIN_RUN_DEPENDS=	kdeadmin>=${KDE_APPLICATIONS_VERSION}:sysutils/kdeadmin

KDEBASE_DESC=		Base KDE applications
KDEBASE_RUN_DEPENDS=	kde-baseapps>=${KDE_APPLICATIONS_VERSION}:x11/kde-baseapps

KDEEDU_DESC=		Entertaining, educational programs
KDEEDU_RUN_DEPENDS=	kdeedu>=${KDE_APPLICATIONS_VERSION}:misc/kdeedu

KDEGAMES_DESC=		Collection of games
KDEGAMES_RUN_DEPENDS=	kdegames>=${KDE_APPLICATIONS_VERSION}:games/kdegames

KDEGRAPHICS_DESC=	Graphics utilities
KDEGRAPHICS_RUN_DEPENDS=	kdegraphics>=${KDE_APPLICATIONS_VERSION}:graphics/kdegraphics

KDEMULTIMEDIA_DESC=	Multimedia applications
KDEMULTIMEDIA_RUN_DEPENDS=	kdemultimedia>=${KDE_APPLICATIONS_VERSION}:multimedia/kdemultimedia

KDENETWORK_DESC=	Network-related programs
KDENETWORK_RUN_DEPENDS=	kdenetwork>=${KDE_APPLICATIONS_VERSION}:net/kdenetwork

KDEPIM_DESC=		Personal information management
KDEPIM_RUN_DEPENDS=	kdepim>=${KDE_APPLICATIONS_VERSION}:deskutils/kdepim

KDEUTILS_DESC=		Collection of utilities for KDE
KDEUTILS_RUN_DEPENDS=	kdeutils>=${KDE_APPLICATIONS_VERSION}:misc/kdeutils

.include <bsd.port.mk>
