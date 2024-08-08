PORTNAME=	qterminal
PORTVERSION=	2.0.1
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Lightweight Qt-based terminal emulator
WWW=		https://github.com/lxqt/qterminal

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget6.so:x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=		cmake compiler:c++17-lang gettext-runtime kde:6 \
		localbase:ldflags lxqt:2 perl5 pkgconfig qt:6 tar:xz xorg
CMAKE_OFF=	BUILD_TESTS
USE_PERL5=	build
USE_QT=		base:run tools:build
USE_KDE=	layer-shell-qt
USE_XORG=	x11
USE_LXQT=	buildtools2

.include <bsd.port.mk>
