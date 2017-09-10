# $FreeBSD$

PORTNAME=	kactivities
PORTVERSION=	${KDE4_ACTIVITIES_VERSION}
PORTREVISION=	4
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/Attic/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kactivities library

USES=		cmake:outsource compiler:c++11-lib kde:4 tar:xz
USE_KDE=	automoc4 kdelibs soprano nepomuk-core
USE_QT4=	declarative moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/src/lib/core/CMakeLists.txt \
		${WRKSRC}/src/lib/models/CMakeLists.txt
# Disable kactivitymanagerd
	${REINPLACE_CMD} -e "/add_subdirectory (service)/d" \
		-e "/add_subdirectory (workspace)/d" \
		${WRKSRC}/src/CMakeLists.txt \

.include <bsd.port.mk>
