# New ports collection makefile for:	python-xlib
# Date created:		5 December 2001
# Whom:	      		Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	plwm
PORTVERSION=	2.4
CATEGORIES=	x11-wm python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mwm@mired.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib

USE_PYTHON=	yes
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/plwm.info ${PREFIX}/info
	install-info --section=X11 ${PREFIX}/info/plwm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
