# New ports collection makefile for:	python-xlib
# Date created:		5 December 2001
# Whom:	      		Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	xlib
PORTVERSION=	0.9
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-xlib-${PORTVERSION}

MAINTAINER=	mwm@mired.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@cd ${WRKSRC} && ${PYTHON_SETUP} build

do-install:
	@cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 --prefix=${PREFIX}
	@${INSTALL_DATA} ${WRKSRC}/doc/info/python-xlib.info ${PREFIX}/info/
	@install-info ${PREFIX}/info/python-xlib.info ${PREFIX}/info/dir

.include <bsd.port.mk>
