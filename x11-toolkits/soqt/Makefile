PORTNAME=	SoQt
PORTVERSION=	1.6.0
PORTREVISION=	1
PORTEPOCH=		1
CATEGORIES=	x11-toolkits
# cannot USE_GITHUB: submodules required, distfile built by upstream
MASTER_SITES=	https://github.com/coin3d/soqt/releases/download/${PORTNAME}-${PORTVERSION}/
DISTNAME=	soqt-${PORTVERSION}-src

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Qt5-fork of the SoQt toolkit library for Coin
WWW=		https://github.com/coin3d/soqt/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libCoin.so:graphics/Coin

USES=		cmake compiler:c++11-lang dos2unix gl libtool \
		localbase:ldflags pathfix pkgconfig qmake:no_env qt:5 xorg
USE_QT=		buildtools core gui opengl qmake widgets
USE_GL=		gl glu
USE_XORG=	ice sm x11 xext xi
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${QT_INCDIR}/QtCore -I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}

WRKSRC=		${WRKDIR}/soqt

.include <bsd.port.mk>
