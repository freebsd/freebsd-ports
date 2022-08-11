PORTNAME=	SoQt
PORTVERSION=	1.6.0
PORTREVISION=	1
PORTEPOCH=		1
CATEGORIES=	x11-toolkits
# cannot use GITHUB - submodules required
MASTER_SITES=	https://bitbucket.org/Coin3D/soqt/downloads/
DISTNAME=	soqt-${PORTVERSION}-src

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Qt5-fork of the SoQt toolkit library for Coin

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libCoin.so:graphics/Coin

USES=		cmake compiler:c++11-lang dos2unix gl libtool \
		localbase:ldflags pathfix pkgconfig qmake:no_env qt:5 xorg zip
USE_QT=		buildtools core gui opengl qmake widgets
USE_GL=		gl
USE_XORG=	ice sm x11 xext xi
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${QT_INCDIR}/QtCore -I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}

WRKSRC=		${WRKDIR}/soqt

.include <bsd.port.mk>
