# New ports collection makefile for:	plasma-scriptengine-ruby
# Date created:		2010-03-30
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plasma-scriptengine-ruby
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kde-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/KDE/plasma.rb:${PORTSDIR}/devel/kdebindings4-ruby-korundum

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
DISTINFO_FILE=	${PORTSDIR}/x11/kde4-workspace/distinfo
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/ruby
CMAKE_OUTSOURCE=	yes

.include <bsd.port.mk>
