# New ports collection makefile for:	pmw
# Version required:	0.8
# Date created:		03 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/11/24 10:10:21 tg Exp $

DISTNAME=	Pmw.0.8
PKGNAME=	py-pmw-0.8
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.dscpl.com.au/pub/pmw/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

PLIST_SUB=	PMWVERSION="${PMWVERSION}"

PYTHONSCRIPTDIR=${PREFIX}/lib/python1.5
SITEPYDIR=	${PYTHONSCRIPTDIR}/site-packages
DOCDIR=		${PREFIX}/share/doc/Pmw
EXAMPLEDIR=	${PREFIX}/share/examples/Pmw
PMWVERSION=	Pmw_0_8

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${SITEPYDIR}
	@(cd ${WRKDIR}; tar cf - Pmw/__init__.py Pmw/${PMWVERSION}/__init__.py Pmw/${PMWVERSION}/lib) | \
	    (cd ${SITEPYDIR}; tar xf -)
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${SITEPYDIR}/Pmw
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${SITEPYDIR}/Pmw
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR} ${EXAMPLEDIR}
	@(cd ${WRKDIR}/Pmw/${PMWVERSION}/doc; tar cf - .) | \
		(cd ${DOCDIR}; tar xf -)
	@(cd ${WRKDIR}/Pmw/${PMWVERSION}/demos; tar cf - .) | \
		(cd ${EXAMPLEDIR}; tar xf -)
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${EXAMPLEDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${EXAMPLEDIR}
.endif

.include <bsd.port.mk>
