# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kiwi
PORTVERSION=	1.9.29
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://download.gnome.org/sources/${PORTNAME}/1.9/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework and a set of enhanced widgets based on PyGTK

USES=		gettext tar:xz
USE_GNOME=	libglade2 pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
