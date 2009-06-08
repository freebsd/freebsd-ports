# New ports collection makefile for:	python-xlib
# Date created:		5 December 2001
# Whom:	      		Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	plwm
PORTVERSION=	2.5
PORTREVISION=	1
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

post-patch:
	${REINPLACE_CMD} -e 's,whrandom,random,g' ${WRKSRC}/plwm/inspect.py
	${REINPLACE_CMD} -e 's,$$Id,coding: utf-8 ,g' ${WRKSRC}/plwm/mw_apm.py

pre-install:
	makeinfo -o ${PREFIX}/info/plwm.info ${WRKSRC}/doc/plwm.texi

.include <bsd.port.mk>
