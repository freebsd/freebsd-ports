PORTNAME=	qtermwidget
PORTVERSION=	1.4.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	LXQT
PKGNAMESUFFIX=	-qt5

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Terminal widget for QTerminal (Qt5)
WWW=		https://github.com/lxde/qtermwidget

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gettext-runtime lxqt:1 \
		pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_QT=		buildtools:build core gui qmake:build linguisttools widgets
USE_LXQT=	buildtools

CMAKE_ARGS+=	-DQTERMWIDGET_USE_UTEMPTER=ON

.include <bsd.port.mk>
