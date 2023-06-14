PORTNAME=	tktreectrl
PORTVERSION=	2.0.2
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	SF/tkintertreectrl/TkinterTreectrl-${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TkTreectrl Python bindings
WWW=		http://tkintertreectrl.sourceforge.net/

LICENSE=	PD

# x11-toolkits/tktreectrl does not provide libtreectrl.so
LIB_DEPENDS=	libtreectrl.so.1:x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Pmw>=0:x11-toolkits/py-Pmw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python tk:run zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
