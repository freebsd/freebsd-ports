PORTNAME=	qml-box2d
DISTVERSION=	2.0.20180109
PORTREVISION=	5
CATEGORIES=	x11-toolkits

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML Box2D plugin
WWW=		https://github.com/qml-box2d/qml-box2d

USES=		compiler:c++11-lang gl qmake:outsource qt:5
USE_GITHUB=	yes
GH_TAGNAME=	21e57f
USE_GL=		gl
USE_QT=		core declarative gui network \
		buildtools:build qmake:build
USE_LDCONFIG=	${QT_QMLDIR}/Box2D.2.0/

.include <bsd.port.mk>
