# New ports collection makefile for:	python-xlib
# Date created:		5 December 2001
# Whom:	      		Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	plwm
PORTVERSION=	2.5
CATEGORIES=	x11-wm python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mwm@mired.org
COMMENT=	A window manager construction kit

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib

INFO=		plwm

USE_PYTHON=	yes
GNU_CONFIGURE=	yes

pre-install:
	makeinfo -o ${PREFIX}/info/plwm.info ${WRKSRC}/doc/plwm.texi
	install-info --section=X11 ${PREFIX}/info/plwm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
