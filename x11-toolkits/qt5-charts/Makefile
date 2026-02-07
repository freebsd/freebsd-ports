PORTNAME=	charts
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 charts module

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,charts tar:xz
USE_PERL5=	build
USE_QT=		core declarative network gui widgets designer \
		buildtools:build qmake:build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
