# $FreeBSD$

PORTNAME=	kde-baseapps
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for KDE

LIB_DEPENDS=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib

CONFLICTS=	kdebase-4.[0-6].* konq-plugins-4.[0-6].*

USE_XZ=		yes
USE_GNOME=	glib20
USE_KDE4=	kdehier kdelibs kdeprefix libkonq \
		automoc4 soprano strigi nepomuk-core \
		nepomuk-widgets kactivities
USES=		cmake:outsource gettext
USE_QT4=	corelib dbus gui script xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xt
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"

MAN1=		kbookmarkmerger.1 \
		kfind.1

OPTIONS_DEFINE=	KONSOLE KWRITE
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

KONSOLE_DESC=	Install Konsole terminal emulator
KWRITE_DESC=	Install KWrite text editor

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKONSOLE}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/konsole:${PORTSDIR}/x11/konsole
.endif

.if ${PORT_OPTIONS:MKWRITE}
USE_KDE4+=	kate_run
.endif

pre-configure:
# Quick hack to avoid building libkonq here
	${REINPLACE_CMD} -e '/add_subdirectory (konq)/d' \
		${WRKSRC}/lib/CMakeLists.txt
	${MKDIR} ${BUILD_WRKSRC}/lib && \
	${LN} -s ${KDE4_PREFIX}/lib/libkonq.so ${BUILD_WRKSRC}/lib

.include <bsd.port.mk>
