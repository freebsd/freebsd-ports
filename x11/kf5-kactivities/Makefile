PORTNAME=	kactivities
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 runtime and library to organize work in separate activities

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	config coreaddons service \
		ecm:build
USE_QT=		core dbus declarative gui network sql \
		buildtools:build qmake:build

.include <bsd.port.options.mk>

.if !${ABI:Mpurecap}
BUILD_DEPENDS=	boost-libs>1.53:devel/boost-libs
.endif

.include <bsd.port.mk>
