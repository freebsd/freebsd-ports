# New ports collection makefile for:	python-xlib
# Date created:		5 December 2001
# Whom:	      		Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	xlib
PORTVERSION=	0.12
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-xlib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-xlib-${PORTVERSION}

MAINTAINER=	mwm@mired.org
COMMENT=	X11 library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/info/python-xlib.info ${PREFIX}/info/
	@install-info ${PREFIX}/info/python-xlib.info ${PREFIX}/info/dir

.include <bsd.port.mk>
