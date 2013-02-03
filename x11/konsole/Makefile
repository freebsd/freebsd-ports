# $FreeBSD$

PORTNAME=	konsole
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator

CONFLICTS=	kdebase-4.[0-6].*

USE_XZ=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4 libkonq
KDE4_BUILDENV=	yes
USE_QT4=	xml moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xrender
CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
