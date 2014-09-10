# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	fltk
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
#MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${DISTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyFltk-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to FLTK window toolkit

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_XORG=	x11

MAKE_ENV+=	FLTK_HOME=${LOCALBASE}/bin
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
XTRADOCS=	CHANGES README TODO
CFLAGS+=	-DFL_LIBRARY

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${LOCALBASE}|g;s|package_data.*},||g;s|sunos5|freebsd8', 'freebsd9', 'freebsd10|g" ${WRKSRC}/setup.py

post-build:
	${REINPLACE_CMD} -e "s|\.\./docs|${DOCSDIR}/html|g" ${WRKSRC}/fltk/test/help.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/fltk/docs/*.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/fltk/docs/*.jpg ${STAGEDIR}${DOCSDIR}/html
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/fltk/test/*.py ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/fltk/test/HelpDialog.html ${STAGEDIR}${EXAMPLESDIR}
.for i in ${XTRADOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
