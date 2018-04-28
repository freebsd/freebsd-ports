# $FreeBSD$

PORTNAME=	kde-baseapps
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE5 baseapps meta port

LICENSE=	LGPL20

USES=		kde:5 metaport
RUN_DEPENDS=	dolphin>=${KDE_APPLICATIONS_VERSION}:x11-fm/dolphin  \
		gwenview>=${KDE_APPLICATIONS_VERSION}:graphics/gwenview \
		kate>=${KDE_APPLICATIONS_VERSION}:editors/kate \
		kdialog>=${KDE_APPLICATIONS_VERSION}:sysutils/kdialog \
		keditbookmarks>=${KDE_APPLICATIONS_VERSION}:deskutils/keditbookmarks \
		khelpcenter>=${KDE_APPLICATIONS_VERSION}:sysutils/khelpcenter \
		konsole>=${KDE_APPLICATIONS_VERSION}:x11/konsole \
		konqueror>=${KDE_APPLICATIONS_VERSION}:x11-fm/konqueror \
		okular>=${KDE_APPLICATIONS_VERSION}:graphics/okular

.include <bsd.port.mk>
