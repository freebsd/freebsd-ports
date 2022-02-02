PORTNAME=	dsbxinput
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Graphical tool for configuring pointing devices

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xinput:x11/xinput

USES=		pyqt:5 python:3.8+ qt:5
USE_QT=		linguisttools_build
USE_GITHUB=	yes
GH_ACCOUNT=	mrclksr
GH_PROJECT=	DSBXinput
USE_PYQT=	pyqt5

BINARY_ALIAS=	lrelease=${LRELEASE}
.include <bsd.port.mk>
