# New ports collection makefile for:	py-anygui
# Date created:		29 October 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anygui
PORTVERSION=	0.1.1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic GUI-creation front-end for Python

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGELOG.txt KNOWN_BUGS.txt README.txt MAINTAINERS.txt TODO.txt doc/*
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
