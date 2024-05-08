PORTNAME=	qt6pas
PORTVERSION=	6.2.8
CATEGORIES=	x11-toolkits
MASTER_SITES=	LOCAL/acm/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Qt6 binding for FreePascal
WWW=		https://wiki.lazarus.freepascal.org/index.php/Qt6_Interface

LICENSE=	LGPL3LE
LICENSE_NAME=	GNU Lesser General Public License version 3 Link Exception
LICENSE_FILE=	${WRKSRC}/COPYING.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c++11-lang gl qmake qt:6
USE_GL=		opengl
USE_QT=		base
USE_LDCONFIG=	yes

QT6_VER_MIN=	6.2.8

post-patch:
	@${REINPLACE_CMD} -e 's|-mincoming-stack-boundary=2||g' ${WRKSRC}/Qt6Pas.pro

.include <bsd.port.mk>
