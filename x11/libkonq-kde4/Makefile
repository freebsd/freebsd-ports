# $FreeBSD$

PORTNAME=	libkonq
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	6
CATEGORIES=	x11 kde kde-kde4
DISTNAME=	kde-baseapps-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core library for Konqueror

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libphonon.so:multimedia/phonon@qt4

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4 soprano
USE_QT=		corelib dbus gui network svg xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
USE_XORG=	x11

DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde-baseapps-kde4/distinfo

BUILD_WRKSRC=	${CONFIGURE_WRKSRC}/lib/konq
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
