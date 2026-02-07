PORTNAME=	quickcontrols2
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of controls for building complete interfaces in Qt Quick
WWW=		https://qt-project.org

BROKEN_armv6=		fails to install: pkg-static: Unable to access file DayOfWeekRow.qmlc: No such file or directory

USES=		compiler:c++11-lang perl5 qmake:norecursive qt-dist:5
USE_PERL5=	build
USE_QT=		core declarative gui widgets \
		buildtools:build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
QT_DIST=	${PORTNAME}

.include <bsd.port.mk>
