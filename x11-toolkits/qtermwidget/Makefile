# $FreeBSD$

PORTNAME=	qtermwidget
PORTVERSION=	0.9.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Terminal widget for QTerminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: Emulation.cpp:135:14: 'ScreenWindow' does not refer to a value
BROKEN_armv6=		fails to compile: Emulation.cpp:135:14: 'ScreenWindow' does not refer to a value
BROKEN_armv7=		fails to compile: Emulation.cpp:135:14: 'ScreenWindow' does not refer to a value

USES=	cmake:outsource compiler:c++11-lang gettext-runtime lxqt \
	pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core gui qmake_build linguisttools widgets
USE_LXQT=	buildtools
CMAKE_ARGS+=    -DQTERMWIDGET_USE_UTEMPTER=ON
.include <bsd.port.mk>
