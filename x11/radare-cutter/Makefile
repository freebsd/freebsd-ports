# $FreeBSD$

PORTNAME=	radare-cutter
PORTVERSION=	1.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI for radare2 reverse engineering framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libr_bin.so:devel/radare2

USES=		pkgconfig python:3.4+ qmake:outsource qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_PROJECT=	cutter

USE_QT=		buildtools_build core gui location network qml quick svg \
		webchannel webengine widgets
USE_GL=		gl

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/Cutter \
		share/appdata/Cutter.appdata.xml \
		share/applications/Cutter.desktop \
		share/pixmaps/cutter.svg

post-patch:
	@${REINPLACE_CMD} 's/python3/python-${PYTHON_VER}/' ${WRKSRC}/Cutter.pro

.include <bsd.port.mk>
