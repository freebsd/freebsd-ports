# $FreeBSD$

PORTNAME=	radare-cutter
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI for radare2 reverse engineering framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libr2.so:devel/radare2

USES=		pkgconfig qmake
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_PROJECT=	cutter

USE_QT5=	buildtools_build core gui svg widgets

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/cutter \
		share/applications/cutter.desktop \
		share/pixmaps/cutter.svg

.include <bsd.port.mk>
