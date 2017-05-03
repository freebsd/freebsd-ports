# Created by: tcberner
# $FreeBSD$

PORTNAME=	krunner
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 parallelized query system

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	config coreaddons ecm i18n kio package plasma-framework \
		service solid threadweaver
USE_QT5=	buildtools_build core gui network qmake_build qml \
		quick widgets

.include <bsd.port.mk>
