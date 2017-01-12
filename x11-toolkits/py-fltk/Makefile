# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	fltk
PORTVERSION=	1.3.3.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/pyFltk-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyFltk-${PORTVERSION}_py3

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FLTK window toolkit

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

CFLAGS+=	-DFL_LIBRARY
MAKE_ENV=	FLTK_HOME=${LOCALBASE}/bin
USE_PYTHON=	autoplist distutils
USE_XORG=	x11
USES=		python

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*
WRKSRC=		${WRKDIR}/pyFltk-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${LOCALBASE}|g;s|package_data.*},||g;s|sunos5|dragonfly4', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11', 'freebsd12|g" ${WRKSRC}/setup.py

post-build:
	${REINPLACE_CMD} -e "s|\.\./docs|${DOCSDIR}/html|g" ${WRKSRC}/fltk/test/help.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fltk/_fltk.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES README TODO ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/fltk/docs/ && ${INSTALL_DATA} *.html *.jpg ${STAGEDIR}${DOCSDIR}/html/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/fltk/test/ && ${INSTALL_DATA} *.py HelpDialog.html ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
