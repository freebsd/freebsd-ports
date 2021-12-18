PORTNAME=	uiplugin
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Custom Qt widget plugin interface for Qt Designer

USES=		compiler:c++17-lang perl5 qmake qt-dist:5,tools
USE_PERL5=	extract
USE_QT=		core gui widgets \
		buildtools_build # syncqt

BUILD_WRKSRC=	${WRKSRC}/src/designer/src/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/designer/src/${PORTNAME}

.include <bsd.port.mk>
