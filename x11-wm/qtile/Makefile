# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	qtile
PORTVERSION=	0.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-wm

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Small, flexible, scriptable tiling window manager written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}cffi>1.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>1.4.1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>0.7:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xcffib>=0.5.0:x11/py-xcffib@${PY_FLAVOR}
LIB_DEPENDS=	libpangocairo-1.0.so:x11-toolkits/pango
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xcffib>=0.5.0:x11/py-xcffib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>0.7:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncio>0:devel/py-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	qtile

USE_GNOME=	pygobject3

USES=		python:3.4+
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

PORTDOCS=	CHANGELOG README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
