# New ports collection makefile for:	py-pyqwt
# Date created:		2009-01-20
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyqwt
PORTVERSION=	5.2.0
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}5/PyQwt-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQwt-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Bindings for the Qwt Class Library

BUILD_DEPENDS=	${LOCALBASE}/bin/qmake-qt4:${PORTSDIR}/devel/qmake4 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.5.4:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.5.4:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.5.4:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.4.1:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5

USE_PYTHON=	2.5+
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

post-patch:
		${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
			${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
