PORTNAME=	albert
DISTVERSION=	0.30.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/albertlauncher/albert/releases/download/v${DISTVERSION}/
DISTFILES=	v${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Albert a keyboard launcher
WWW=		https://github.com/albertlauncher/albert

LICENSE=	GPLv3

BUILD_DEPENDS=	pybind11>=2.4.3:devel/pybind11
LIB_DEPENDS=	libmuparser.so:math/muparser \
		libqalculate.so:math/libqalculate \
		libqt6keychain.so:security/qtkeychain@qt6
RUN_DEPENDS=	play:audio/sox

USES=	cmake compiler:c++23-lang gl libarchive localbase:ldflags pkgconfig python qt:6 xorg

USE_GL=	gl opengl
USE_QT=	base declarative scxml svg translations
USE_XORG=x11 xext sm ice
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
