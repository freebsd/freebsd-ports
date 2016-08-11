# $FreeBSD$

PORTNAME=	kactivitymanagerd
PORTVERSION=	${KDE4_ACTIVITES_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/Attic/${PORTVERSION}/src
DISTNAME=	kactivities-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Activity Manager daemon

USE_KDE4=	automoc4 kdelibs soprano nepomuk-core \
		kactivities
USES=		cmake:outsource compiler:c++11-lib tar:xz
USE_QT4=	declarative opengl script sql \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
DISTINFO_FILE=	${.CURDIR}/../kactivities/distinfo
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

# https://bugs.kde.org/show_bug.cgi?id=305529#c10
CMAKE_ARGS+=	-DCMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS=-rdynamic

.include <bsd.port.pre.mk>

# Workaround to keep kactivitymanagerd from crashing:
# http://lists.freebsd.org/pipermail/freebsd-current/2012-May/033972.html
.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1000000
CXXFLAGS+=	-fno-use-cxa-atexit
.endif

post-patch:
	${REINPLACE_CMD} -e "/add_subdirectory (lib)/d" \
		-e "/add_subdirectory (ontologies)/d" \
		${WRKSRC}/src/CMakeLists.txt \

.include <bsd.port.post.mk>
