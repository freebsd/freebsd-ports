# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kiwi
PORTVERSION=	1.9.38
DISTVERSIONPREFIX=	gtk-
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP/source/${DISTNAME:C/(.).*/\1/}/${PORTNAME}-gtk
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Framework and a set of enhanced widgets based on PyGTK

LICENSE=	LGPL21

NO_ARCH=	yes

USES=		gettext uniquefiles:dirs
USE_GNOME=	libglade2 pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
