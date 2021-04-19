PORTNAME=	dsbxinput
DISTVERSION=	0.1
CATEGORIES=	x11

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Graphical tool for configuring pointing devices

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lrelease:devel/qt5-linguisttools
RUN_DEPENDS=	xinput:x11/xinput

USES=		pyqt:5 python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	mrclksr
GH_PROJECT=	DSBXinput
USE_PYQT=	core gui widgets

.include <bsd.port.mk>
