# $FreeBSD$

PORTNAME=	plasma-scriptengine-ruby
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kde-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Ruby

USE_KDE4=	kdehier kdelibs kdeprefix korundum automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
DISTINFO_FILE=	${PORTSDIR}/x11/kde4-workspace/distinfo
USE_XZ=		yes
USES=		cmake:outsource

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/ruby

NO_STAGE=	yes
.include <bsd.port.mk>
