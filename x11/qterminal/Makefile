# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	qterminal
PORTVERSION=	0.7.0
CATEGORIES=	x11

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf \
	qterminal-l10n>0:x11/qterminal-l10n

USES=		cmake:outsource compiler:c++11-lang localbase:ldflags \
		lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build core gui qmake_build widgets x11extras
USE_XORG=	x11
USE_LXQT=	buildtools lxqt

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT:BOOL=OFF

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
LDFLAGS+=	-lulog
.endif

.include <bsd.port.post.mk>
