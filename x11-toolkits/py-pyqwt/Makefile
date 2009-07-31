# New ports collection makefile for:	py-pyqwt
# Date created:		2009-01-20
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyqwt
PORTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQwt-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Bindings for the Qwt Class Library

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.3.3:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.3.3:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.3.3:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.2:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5

USE_PYTHON=	2.5+
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

BROKEN=		does not compile

.include <bsd.port.mk>
