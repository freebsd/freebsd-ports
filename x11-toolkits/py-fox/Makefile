# New ports collection makefile for:	py-fox
# Date created:		5 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.0.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fxpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FXPy-${PORTVERSION}

MAINTAINER=	hsn@netmag.cz
COMMENT=	Python interface to FOX Graphics library

LIB_DEPENDS=	FOX-1.0:${PORTSDIR}/x11-toolkits/fox

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_XLIB=	yes

WRKSRC=		${WRKDIR}/FXPy-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} install ${PYDISTUTILS_INSTALLARGS})
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.xml ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/examples/icons/*.png ${EXAMPLESDIR}/icons
.endif

.include <bsd.port.mk>
