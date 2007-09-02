# New ports collection makefile for:	pmw
# Date created:		03 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pmw
PORTVERSION=	1.3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	High-level compound graphics widgets for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
LIB_DEPENDS=	BLT24.3:${PORTSDIR}/x11-toolkits/blt

PLIST_SUB=	PMWVERSION="${PMWVERSION}"
USE_PYTHON=	yes

PMWVERSION=	${PORTNAME}_${PORTVERSION:S/./_/g}
WRKSRC=		${WRKDIR}/src

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@(cd ${WRKSRC}; ${TAR} cf - Pmw/__init__.py Pmw/${PMWVERSION}/__init__.py Pmw/${PMWVERSION}/lib) | \
	    (cd ${PYTHON_SITELIBDIR}; ${TAR} xf -)
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/Pmw
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/Pmw

	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}; ${TAR} cf - bin) | \
		(cd ${DATADIR}; ${TAR} xf -)
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}; ${TAR} cf - contrib) | \
		(cd ${DATADIR}; ${TAR} xf -)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}/doc; ${TAR} cf - .) | \
		(cd ${DOCSDIR}; ${TAR} xf -)
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}/demos; ${TAR} cf - .) | \
		(cd ${EXAMPLESDIR}; ${TAR} xf -)
.endif

.include <bsd.port.mk>
