# New ports collection makefile for:	py-kiwi
# Date created:		2006-05-04
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	kiwi
PORTVERSION=	1.9.26
PORTREVISION=	3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://download.gnome.org/sources/${PORTNAME}/1.9/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A framework and a set of enhanced widgets based on PyGTK

BUILD_DEPENDS=	pygtk-codegen-2.0:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	pygtk-codegen-2.0:${PORTSDIR}/x11-toolkits/py-gtk2

USE_GETTEXT=	yes
USE_GNOME=	libglade2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

FETCH_ARGS=	-rRp

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if defined (WITH_ZOPEINTERFACE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/devel/py-zopeInterface
.endif

.if defined (WITH_PYGOBJECT)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gobject>=2.14.2_2:${PORTSDIR}/devel/py-gobject
.endif

.if defined (WITH_PYSQLOBJECT)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlobject>=0.10.0_1:${PORTSDIR}/databases/py-sqlobject
.endif

.include <bsd.port.post.mk>
