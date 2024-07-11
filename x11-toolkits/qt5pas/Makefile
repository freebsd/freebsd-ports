PORTNAME=	qt5pas
PORTVERSION=	2.6
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	LOCAL/acm/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Qt5 binding for FreePascal
WWW=		https://wiki.lazarus.freepascal.org/index.php/Qt_Interface

LICENSE=	LGPL3LE
LICENSE_NAME=	GNU Lesser General Public License version 3 Link Exception
LICENSE_FILE=	${WRKSRC}/COPYING.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c++11-lang qmake qt:5
USE_QT=		buildtools:build core gui network printsupport x11extras
USE_LDCONFIG=	yes

QT5_VER_MIN=	5.6.1

post-patch:
	@${REINPLACE_CMD} -e 's|-mincoming-stack-boundary=2||g' ${WRKSRC}/Qt5Pas.pro

.include <bsd.port.mk>
