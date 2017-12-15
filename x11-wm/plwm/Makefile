# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	plwm
PORTVERSION=	2.6a
CATEGORIES=	x11-wm python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager construction kit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>0:x11-toolkits/py-xlib@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>0:x11-toolkits/py-xlib@${FLAVOR}

NO_ARCH=	yes

USES=		python:2.7
USE_PYTHON=	distutils autoplist

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|whrandom|random|g' ${WRKSRC}/plwm/inspect.py
	@${REINPLACE_CMD} -e \
		's|$$Id|coding: utf-8 |g' ${WRKSRC}/plwm/mw_apm.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.pdf \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} *.examplewm *.py \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
