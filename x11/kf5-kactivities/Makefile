PORTNAME=	kactivities
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 runtime and library to organize work in separate activities

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	config coreaddons service \
		ecm:build
USE_QT=		core dbus declarative gui network sql \
		buildtools:build qmake:build

OPTIONS_DEFINE=			QML
OPTIONS_DEFAULT=		QML
OPTIONS_EXCLUDE_purecap=	QML
OPTIONS_SUB=			yes

.include <bsd.port.options.mk>

.if ${ABI:Mpurecap}
CMAKE_ARGS+=	-DKACTIVITIES_LIBRARY_ONLY=ON
.else
BUILD_DEPENDS=	boost-libs>1.53:devel/boost-libs
.endif

.include <bsd.port.mk>
