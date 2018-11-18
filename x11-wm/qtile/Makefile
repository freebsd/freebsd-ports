# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	qtile
PORTVERSION=	0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, flexible, scriptable tiling window manager written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	does not run
EXPIRATION_DATE=	2018-12-19
BROKEN=		does not run

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xpyb>0:x11/xpyb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	qtile

USE_GNOME=	pygobject pygtk2

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	CHANGELOG INSTALL.rst README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
