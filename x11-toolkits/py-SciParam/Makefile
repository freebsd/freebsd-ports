# ex:ts=8
# Ports collection makefile for:	py-SciParam
# Date created:			Mar 23, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	SciParam
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.intevation.de/great-er/sciparam/ \
		http://ftp.intevation.de/great-er/sciparam/ \
		ftp://ftp.gwdg.de/pub/misc/freegis/intevation/great-er/sciparam/ \
		http://ftp.gwdg.de/pub/misc/freegis/intevation/great-er/sciparam/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific Parameter Dialogs in wxPython based user interfaces

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*
.endif

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
