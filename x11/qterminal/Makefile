# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	qterminal
PORTVERSION=	0.8.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf \
	qterminal-l10n>0:x11/qterminal-l10n

USES=	cmake:outsource compiler:c++11-lang gettext-runtime \
	localbase:ldflags lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build core gui qmake_build dbus linguisttools \
	widgets x11extras
USE_XORG=	x11
USE_LXQT=	buildtools lxqt

.include <bsd.port.mk>
