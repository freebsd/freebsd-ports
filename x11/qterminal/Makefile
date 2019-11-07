# $FreeBSD$

PORTNAME=	qterminal
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=	cmake compiler:c++11-lang gettext-runtime \
	localbase:ldflags lxqt pkgconfig qt:5 tar:xz xorg
USE_QT=		buildtools_build core gui qmake_build dbus linguisttools \
		widgets x11extras
USE_XORG=	x11
USE_LXQT=	buildtools

.include <bsd.port.mk>
