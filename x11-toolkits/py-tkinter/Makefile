# New ports collection makefile for:    py-Tkinter
# Date created:         12 Jan 1999
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkinter
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.python.org/ftp/python/${PORTVERSION}/ \
		http://SunSITE.Informatik.RWTH-Aachen.DE/python/ftp/python/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${PYTHON_WRKSRC}/Modules

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
