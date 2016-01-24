# $FreeBSD$

PORTNAME=	uiplugin
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Custom Qt widget plugin interface for Qt Designer

# This port used to be part of qt5-designer itself before 5.5.0.
CONFLICTS=	qt5-designer-5.[0-4].*

USE_QT5=	core gui widgets
QT_DIST=	tools
USES=		qmake

BUILD_WRKSRC=   ${WRKSRC}/src/designer/src/${PORTNAME}
INSTALL_WRKSRC= ${WRKSRC}/src/designer/src/${PORTNAME}

.include <bsd.port.mk>
