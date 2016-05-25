# $FreeBSD$

PORTNAME=	kde-baseapps
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for KDE

LIB_DEPENDS=	libtidy.so:www/tidy-lib

USE_GNOME=	glib20
USE_KDE4=	kdelibs baloo baloo-widgets libkonq \
		automoc4 kactivities
USES=		cmake:outsource gettext tar:xz
USE_QT4=	corelib dbus gui script xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xt
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"

OPTIONS_DEFINE=	KONSOLE KWRITE
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

KONSOLE_DESC=	Install Konsole terminal emulator
KONSOLE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/konsole:x11/konsole

KWRITE_DESC=	Install KWrite text editor
KWRITE_USE=	KDE4=kate_run

pre-configure:
# Quick hack to avoid building libkonq here
	${REINPLACE_CMD} -e '/add_subdirectory (konq)/d' \
		${WRKSRC}/lib/CMakeLists.txt
	${MKDIR} ${BUILD_WRKSRC}/lib && \
	${LN} -s ${KDE4_PREFIX}/lib/libkonq.so ${BUILD_WRKSRC}/lib

.include <bsd.port.mk>
