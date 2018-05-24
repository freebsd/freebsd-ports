# $FreeBSD$

PORTNAME=	radare-cutter
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI for radare2 reverse engineering framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	python3:lang/python3
RUN_DEPENDS=	python3:lang/python3

LIB_DEPENDS=	libr2.so:devel/radare2

USES=		pkgconfig python:3.4+ qmake
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_PROJECT=	cutter

USE_QT5=	buildtools_build core gui svg webengine widgets

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/Cutter \
		share/applications/Cutter.desktop \
		share/pixmaps/cutter.svg

.include <bsd.port.mk>
