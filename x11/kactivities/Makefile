# $FreeBSD$

PORTNAME=	kactivities
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kactivities library

CONFLICTS_INSTALL=	kdelibs-4.7.* kde-runtime-4.7.*

USE_XZ=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
KDE4_BUILDENV=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/lib/CMakeLists.txt

.include <bsd.port.mk>
