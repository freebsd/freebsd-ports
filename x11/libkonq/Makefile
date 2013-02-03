# $FreeBSD$

PORTNAME=	libkonq
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kde-baseapps-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core library for Konqueror

CONFLICTS_INSTALL=	kdebase-4.[0-6].* kde-baseapps-4.7.*

USE_XZ=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

DISTINFO_FILE=	${PORTSDIR}/x11/kde4-baseapps/distinfo

BUILD_WRKSRC=	${CONFIGURE_WRKSRC}/lib/konq
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
