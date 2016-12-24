# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kiwi-gtk
PORTVERSION=	1.9.38
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Framework and a set of enhanced widgets based on PyGTK

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_ARCH=	yes
USE_GNOME=	libglade2 pygtk2
USE_PYTHON=	autoplist distutils
USES=		gettext python uniquefiles:dirs

PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
