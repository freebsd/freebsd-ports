PORTNAME=	dsbxinput
DISTVERSION=	0.1.2
CATEGORIES=	x11

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Graphical tool for configuring pointing devices
WWW=		https://github.com/mrclksr/DSBXinput

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xinput:x11/xinput

USES=		pyqt:5 python qt:5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	mrclksr
GH_PROJECT=	DSBXinput

USE_PYQT=	pyqt5
USE_QT=		linguisttools:build

SHEBANG_FILES=	dsbxinput.in

NO_ARCH=	yes

.include <bsd.port.mk>
