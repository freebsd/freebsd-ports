# $FreeBSD$

PORTNAME=	kactivities
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kactivities library

CONFLICTS_INSTALL=	kdelibs-4.7.* kde-runtime-4.7.*

USE_XZ=		yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix soprano nepomuk-core
USES=		cmake:outsource compiler:c++11-lib
USE_QT4=	declarative moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/src/lib/core/CMakeLists.txt \
		${WRKSRC}/src/lib/models/CMakeLists.txt
# Disable kactivitymanagerd
	${REINPLACE_CMD} -e "/add_subdirectory (service)/d" \
		-e "/add_subdirectory (workspace)/d" \
		${WRKSRC}/src/CMakeLists.txt \

.include <bsd.port.mk>
