# New ports collection makefile for:	qimageblitz
# Date created:		2008-01-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qimageblitz
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/QImageBlitz%20${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphical effects and filters library for KDE4

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e \
	    's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
	    ${WRKSRC}/blitz/CMakeLists.txt

.include <bsd.port.mk>
