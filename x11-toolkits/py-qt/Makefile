# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.9
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyQt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	eugos@gmx.net
COMMENT=	Python bindings for the Qt toolkit

BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_QT_VER=	3
USE_PYTHON=	yes

do-configure:
	@(cd ${WRKSRC} && ${ECHO} "yes" | ${PYTHON_CMD} configure.py \
		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-v ${PREFIX}/share/sip)

.include <bsd.port.mk>
