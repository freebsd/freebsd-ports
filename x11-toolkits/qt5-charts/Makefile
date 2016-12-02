# $FreeBSD$

PORTNAME=	charts
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 charts module

USES=		qmake
USE_GL=		gl
USE_QT5=	core network gui widgets qml quick designer \
		buildtools_build qmake_build

DESCR=		${.CURDIR:H:H}/devel/${_QT_RELNAME}/pkg-descr

USE_GITHUB=	yes
GH_ACCOUNT=	qt
GH_PROJECT=	qtcharts

pre-configure:
# Manually run syncqt. This can be dropped with the update to 5.7.0 as syncqt
# is run upstream when creating the tarball.
	${MKDIR} ${CONFIGURE_WRKSRC}
	cd ${CONFIGURE_WRKSRC} && ${QT_BINDIR}/syncqt.pl -version ${PORTVERSION}

.include <bsd.port.mk>
