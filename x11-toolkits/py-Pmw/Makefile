# New ports collection makefile for:	pmw
# Version required:	0.7
# Date created:		03 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/06/05 06:50:32 tg Exp $

DISTNAME=	Pmw.0.7
PKGNAME=	pmw-0.7
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.dscpl.com.au/pub/pmw/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

PYTHONSCRIPTDIR=${PREFIX}/lib/python1.5
SITEPYDIR=	${PYTHONSCRIPTDIR}/site-packages
DOCDIR=		${PREFIX}/share/doc/Pmw
EXAMPLEDIR=	${PREFIX}/share/examples/Pmw

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@(cd ${WRKDIR}; tar cf - Pmw/__init__.py Pmw/Pmw_0_7/__init__.py Pmw/Pmw_0_7/lib) | \
	    (cd ${SITEPYDIR}; tar xf -)
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${SITEPYDIR}/Pmw
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${SITEPYDIR}/Pmw
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR} ${EXAMPLEDIR}
	@(cd ${WRKDIR}/Pmw/Pmw_0_7/doc; tar cf - .) | \
		(cd ${DOCDIR}; tar xf -)
	@(cd ${WRKDIR}/Pmw/Pmw_0_7/demos; tar cf - .) | \
		(cd ${EXAMPLEDIR}; tar xf -)
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${EXAMPLEDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${EXAMPLEDIR}
.endif

.include <bsd.port.mk>
