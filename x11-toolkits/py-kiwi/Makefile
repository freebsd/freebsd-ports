# New ports collection makefile for:	py-kiwi
# Date created:		2006-05-04
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	kiwi
PORTVERSION=	1.9.14
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://download.gnome.org/sources/${PORTNAME}/1.9/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A framework and a set of enhanced widgets based on PyGTK

BUILD_DEPENDS=	pygtk-codegen-2.0:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GETTEXT=	yes
USE_GNOME=	libglade2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
FIND_DOCSDIR=	api howto

FETCH_CMD=	/usr/bin/fetch -rRp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for d in ${FIND_DOCSDIR}; do \
		${MKDIR} ${DOCSDIR}/$${d}; \
		cd ${WRKSRC}/doc/$${d} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/$${d} ";" ; \
	done;
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} ";"
	cd ${WRKSRC}/examples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} ";"
.endif

.include <bsd.port.pre.mk>

.if defined (WITH_ZOPEINTERFACE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/www/py-zopeInterface
.endif

.include <bsd.port.post.mk>
