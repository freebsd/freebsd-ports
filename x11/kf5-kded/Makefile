# Created by: tcberner
# $FreeBSD$

PORTNAME=	kded
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 extensible deamon for providing system level services

USES=		cmake:outsource compiler:c++11-lib kde:5 tar:xz
USE_KDE=	config coreaddons crash dbusaddons doctools ecm \
		init service
USE_QT5=	buildtools_build core dbus gui qmake_build widgets

.include <bsd.port.mk>
