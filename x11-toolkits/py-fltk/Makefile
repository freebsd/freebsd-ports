# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	fltk
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
#MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${DISTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyFltk-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to FLTK window toolkit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
USE_XORG=	x11

PYDISTUTILS_PKGNAME=	pyFltk

MAKE_ENV+=	FLTK_HOME=${LOCALBASE}/bin
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
XTRADOCS=	CHANGES README TODO
CFLAGS+=	-DFL_LIBRARY

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${LOCALBASE}|g;s|package_data.*},||g;s|sunos5|freebsd8', 'freebsd9', 'freebsd10|g" ${WRKSRC}/setup.py

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
