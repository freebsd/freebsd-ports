# New ports collection makefile for:	pmw
# Date created:		03 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pmw
PORTVERSION=	1.3.2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTNAME}.${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	High-level compound graphics widgets for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
LIB_DEPENDS=	BLT24.3:${PORTSDIR}/x11-toolkits/blt

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PMWVERSION=	${DISTNAME:R:S/./_/g}
PLIST_SUB=	PMWVERSION="${PMWVERSION}"

post-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}/bin; ${TAR} cf - .) | \
		(cd ${DATADIR}; ${TAR} -xof -)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}/doc; ${TAR} cf - .) | \
		(cd ${DOCSDIR}; ${TAR} -xof -)
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for d in  contrib demos
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}; ${TAR} cf - $d) | \
		(cd ${EXAMPLESDIR}; ${TAR} -xof -)
.endfor
.endif

.include <bsd.port.mk>
