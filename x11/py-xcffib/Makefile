# Created by: Eric Turgeon <ericbsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcffib
PORTVERSION=	0.9.0
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Replacement for xpyb and XCB Python bindings

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libxcb.so:x11/libxcb
RUN_DEPENDS=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
