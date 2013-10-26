# $FreeBSD$

PORTNAME=	kactivitymanagerd
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}
DISTNAME=	kactivities-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Activity Manager daemon

CONFLICTS_INSTALL=	kdelibs-4.7.* kde-runtime-4.7.* kactivities-4.[8-9].*

USE_XZ=		yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix soprano nepomuk-core \
		kactivities
USES=		cmake:outsource compiler:c++11-lib
USE_QT4=	declarative opengl script sql \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
DISTINFO_FILE=	${.CURDIR}/../kactivities/distinfo
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

# https://bugs.kde.org/show_bug.cgi?id=305529#c10
CMAKE_ARGS+=	-DCMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS=-rdynamic

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Workaround to keep kactivitymanagerd from crashing:
# http://lists.freebsd.org/pipermail/freebsd-current/2012-May/033972.html
.if ${OSVERSION} > 1000000
CXXFLAGS+=	-fno-use-cxa-atexit
.endif

post-patch:
	${REINPLACE_CMD} -e "/add_subdirectory (lib)/d" \
		-e "/add_subdirectory (ontologies)/d" \
		${WRKSRC}/src/CMakeLists.txt \

.include <bsd.port.post.mk>
