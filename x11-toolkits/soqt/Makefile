PORTNAME=	SoQt
PORTVERSION=	1.6.4
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
# cannot USE_GITHUB: submodules required, distfile built by upstream
MASTER_SITES=	https://github.com/coin3d/soqt/releases/download/v${PORTVERSION}/
DISTNAME=	soqt-${PORTVERSION}-src

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Qt5-fork of the SoQt toolkit library for Coin
WWW=		https://github.com/coin3d/soqt/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libCoin.so:graphics/Coin

USES=		cmake:noninja compiler:c++11-lang dos2unix gl \
		localbase pathfix pkgconfig qmake:no_env qt:6 xorg
USE_QT=		base
USE_GL=		gl glu
USE_XORG=	ice sm x11 xext xi
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${QT_INCDIR}/QtCore -I${QT_INCDIR}
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${QT_LIBDIR} -L${LOCALBASE}/lib
CMAKE_ARGS+=	-DSOQT_USE_QT5=off -DSOQT_USE_QT6=on -DSOQT_VERBOSE="ON"
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/soqt

.include <bsd.port.mk>
