PORTNAME=	qtile
PORTVERSION=	0.18.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Small, flexible, scriptable tiling window manager written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>1.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>1.4.1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>0.7:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xcffib>=0.5.0:x11/py-xcffib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libpangocairo-1.0.so:x11-toolkits/pango \
		libpulse.so:audio/pulseaudio
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xcffib>=0.5.0:x11/py-xcffib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>=0.9:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR}

USE_GNOME=	pygobject3

USES=		gnome python:3.7+ localbase
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

SUB_FILES=	qtile.desktop

PORTDOCS=	CHANGELOG README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	(cd ${WRKDIR} && ${INSTALL_DATA} qtile.desktop \
		${STAGEDIR}${PREFIX}/share/xsessions)

.include <bsd.port.mk>
