PORTNAME=	qterminal
PORTVERSION=	1.3.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Lightweight Qt-based terminal emulator
WWW=		https://github.com/lxqt/qterminal

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=	cmake compiler:c++11-lang gettext-runtime \
	localbase:ldflags lxqt perl5 pkgconfig qt:5 tar:xz xorg
CMAKE_OFF=	BUILD_TESTS
USE_PERL5=	build
USE_QT=		buildtools:build core gui qmake:build dbus linguisttools \
		widgets x11extras
USE_XORG=	x11
USE_LXQT=	buildtools

.include <bsd.port.mk>
