# New ports collection makefile for:	py-fltk
# Date created:		6 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	1.1.b2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pyfltk
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyFltk-${PORTVERSION:S/.b/b/}

MAINTAINER=	hsn@netmag.cz
COMMENT=	Python interface to FLTK window toolkit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes

#WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ENV+=	FLTK_HOME=${X11BASE}/include OPENGL_HOME=${X11BASE}/include
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
XTRADOCS=	CHANGES README TODO

post-build:
	${REINPLACE_CMD} -e "s|\.\./docs|${DOCSDIR}/html|g" ${WRKSRC}/test/help.py

do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} install ${PYDISTUTILS_INSTALLARGS})
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}/html
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.html ${EXAMPLESDIR}
.for i in ${XTRADOCS}
	        ${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
