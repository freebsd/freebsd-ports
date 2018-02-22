# $FreeBSD$

PORTNAME=	libkonq
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	x11 kde kde-kde4
DISTNAME=	kde-baseapps-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core library for Konqueror

LIB_DEPENDS=	libphonon.so:multimedia/phonon

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4 soprano
USE_QT4=	corelib dbus gui network svg xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
USE_XORG=	x11

DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde-baseapps-kde4/distinfo

BUILD_WRKSRC=	${CONFIGURE_WRKSRC}/lib/konq
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
