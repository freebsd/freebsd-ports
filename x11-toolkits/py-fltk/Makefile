# New ports collection makefile for:	py-fltk
# Date created:		6 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pyfltk
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyFltk-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to FLTK window toolkit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_XORG=	x11

PYDISTUTILS_PKGNAME=	pyFltk
PYDISTUTILS_PKGVERSION=	1.1.2

MAKE_ENV+=	FLTK_HOME=${LOCALBASE}/bin
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
XTRADOCS=	CHANGES README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g;s|package_data.*},||g;s|sunos5|freebsd8|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|>mininum|>minimum|g;s|>maxinum|>maximum|g;s|int size_buffer|Py_ssize_t size_buffer|g' ${WRKSRC}/python/fltk_wrap.cpp

post-build:
	${REINPLACE_CMD} -e "s|\.\./docs|${DOCSDIR}/html|g" ${WRKSRC}/fltk/test/help.py

do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} install ${PYDISTUTILS_INSTALLARGS})
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/fltk/docs/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/fltk/docs/*.jpg ${DOCSDIR}/html
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/fltk/test/*.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/fltk/test/HelpDialog.html ${EXAMPLESDIR}
.for i in ${XTRADOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
