# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qimageblitz
PORTVERSION=	0.0.6
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphical effects and filters library for KDE4

USE_LDCONFIG=	yes
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
USES=		cmake tar:bzip2
USE_CXXSTD=	gnu++98

post-patch:
	${REINPLACE_CMD} -e \
		's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/blitz/CMakeLists.txt

.include <bsd.port.mk>
