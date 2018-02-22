# $FreeBSD$

PORTNAME=	plasma-scriptengine-ruby
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
PORTREVISION=	3
CATEGORIES=	x11 kde kde-applications
DISTNAME=	kde-workspace-${PORTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Ruby

NO_ARCH=	yes
USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs korundum automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde-workspace-kde4/distinfo

KDE_APPLICATIONS_VERSION=	15.08.0

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/ruby

.include <bsd.port.mk>
