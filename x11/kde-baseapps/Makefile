PORTNAME=	kde-baseapps
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Base Applications (meta port)
WWW=		https://apps.kde.org/

USES=		kde:6 metaport
RUN_DEPENDS=	dolphin>=${KDE_APPLICATIONS_VERSION}:x11-fm/dolphin \
		gwenview>=${KDE_APPLICATIONS_VERSION}:graphics/gwenview \
		kate>=${KDE_APPLICATIONS_VERSION}:editors/kate \
		kdialog>=${KDE_APPLICATIONS_VERSION}:sysutils/kdialog \
		keditbookmarks>=${KDE_APPLICATIONS_VERSION}:deskutils/keditbookmarks \
		khelpcenter>=${KDE_APPLICATIONS_VERSION}:sysutils/khelpcenter \
		konqueror>=${KDE_APPLICATIONS_VERSION}:x11-fm/konqueror \
		konsole>=${KDE_APPLICATIONS_VERSION}:x11/konsole \
		kwalletmanager>=${KDE_APPLICATIONS_VERSION}:security/kwalletmanager \
		okular>=${KDE_APPLICATIONS_VERSION}:graphics/okular

.include <bsd.port.mk>
