# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	SoQt
PORTVERSION=	1.6.0a
PORTREVISION=	1
PKGNAMESUFFIX=	-devel
DISTNAME=	soqt_${PORTVERSION}
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/FreeCAD/pivy/releases/download/0.6.4/
DIST_SUBDIR=	KDE

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Qt5-fork of the SoQt toolkit library for Coin

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libCoin.so:graphics/Coin

CONFLICTS_INSTALL=	SoQt

USES=		cmake compiler:c++11-lang dos2unix gl libtool \
		localbase:ldflags pathfix pkgconfig qmake:no_env qt:5 xorg
USE_QT=		buildtools core gui opengl qmake widgets
USE_GL=		gl
USE_XORG=	ice sm x11 xext xi
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${QT_INCDIR}/QtCore -I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}

WRKSRC=		${WRKDIR}/soqt

.include <bsd.port.mk>
