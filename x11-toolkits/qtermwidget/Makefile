# $FreeBSD$

PORTNAME=	qtermwidget
PORTVERSION=	0.9.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cmake:outsource compiler:c++11-lang gettext-runtime lxqt \
	pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core gui qmake_build linguisttools widgets
USE_LXQT=	buildtools
CMAKE_ARGS+=	-DQTERMWIDGET_USE_UTEMPTER=ON
.include <bsd.port.mk>
