# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	screenkey
PORTVERSION=	1.4
CATEGORIES=	x11 python
MASTER_SITES=	https://www.thregr.org/~wavexx/software/screenkey/releases/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Screencast tool to display pressed keys

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel@${PY_FLAVOR} 

USES=		gnome python xorg
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist distutils noflavors
USE_XORG=	xtst

post-patch:
	@${REINPLACE_CMD} -e 's,setup_requires=,#&,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
