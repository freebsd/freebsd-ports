PORTNAME=	tktreectrl
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	SF/tkintertreectrl/TkinterTreectrl-${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TkTreectrl Python bindings
WWW=		https://tkintertreectrl.sourceforge.net/

LICENSE=	PD

# x11-toolkits/tktreectrl does not provide libtreectrl.so
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libtreectrl.so.1:x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Pmw>=0:x11-toolkits/py-Pmw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python tk:run zip
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py ${WRKSRC}/TkTreectrl/__init__.py

.include <bsd.port.mk>
