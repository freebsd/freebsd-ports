# New ports collection makefile for:    py-Tkinter
# Date created:         12 Jan 1999
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkinter
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python bindings to the Tk widget set

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

DIST_SUBDIR=	python
PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/_tkinter.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python/distinfo

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
