# New ports collection makefile for:	pmw
# Date created:		03 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-pmw
PORTVERSION=	0.8.4
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.dscpl.com.au/pub/pmw/
DISTNAME=	Pmw.${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

PLIST_SUB=	PMWVERSION="${PMWVERSION}"
USE_PYTHON=	yes

DOCDIR=		${PREFIX}/share/doc/Pmw
EXAMPLEDIR=	${PREFIX}/share/examples/Pmw
PMWVERSION=	Pmw_${PORTVERSION:S/./_/g}

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@(cd ${WRKDIR}; tar cf - Pmw/__init__.py Pmw/${PMWVERSION}/__init__.py Pmw/${PMWVERSION}/lib) | \
	    (cd ${PYTHON_SITELIBDIR}; tar xf -)
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/Pmw
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/Pmw
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR} ${EXAMPLEDIR}
	@(cd ${WRKDIR}/Pmw/${PMWVERSION}/doc; tar cf - .) | \
		(cd ${DOCDIR}; tar xf -)
	@(cd ${WRKDIR}/Pmw/${PMWVERSION}/demos; tar cf - .) | \
		(cd ${EXAMPLEDIR}; tar xf -)
.endif

.include <bsd.port.mk>
