# New ports collection makefile for:	qimageblitz
# Date created:		2008-01-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qimageblitz
PORTVERSION=	0.0.4
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 integrated X11 desktop

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake moc uic gui rcc
USE_CMAKE=	yes
CMAKE_DEBUG=	yes
CMAKE_VERBOSE=	yes

post-patch:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e \
	    's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
	    ${WRKSRC}/blitz/CMakeLists.txt

.include <bsd.port.mk>
