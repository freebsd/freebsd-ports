# $FreeBSD$

PORTNAME=	plasma-scriptengine-ruby
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${KDE4_APPLICATIONS_VERSION}/src
DISTNAME=	kde-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Ruby

USE_KDE4=	kdelibs korundum automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde4-workspace/distinfo
USES=		cmake:outsource tar:xz

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/ruby

.include <bsd.port.mk>
