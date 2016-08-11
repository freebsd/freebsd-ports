# $FreeBSD$

PORTNAME=	libkonq
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kde-baseapps-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core library for Konqueror

USES=		cmake tar:xz
USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib dbus gui \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde4-baseapps/distinfo

BUILD_WRKSRC=	${CONFIGURE_WRKSRC}/lib/konq
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
