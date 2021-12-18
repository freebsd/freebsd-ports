PORTNAME=	x11extras
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt platform-specific features for X11-based systems

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,x11extras perl5
USE_PERL5=	extract
USE_QT=		core gui \
		buildtools_build # syncqt

.include <bsd.port.mk>
