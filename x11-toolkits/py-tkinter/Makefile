# New ports collection makefile for:    py-Tkinter
# Version required:     1.5.2
# Date created:         12 Jan 1999
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	py152
PKGNAME=	py-tkinter-1.5.2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

DIST_SUBDIR=	python
WRKSRC=		${WRKDIR}/Python-1.5.2/Modules
ALL_TARGET=	sharedmods
MAKE_FLAGS=	OPT="${CFLAGS}"

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}
	@${CP} ${PYTHONSCRIPTDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_DATA} ${WRKSRC}/_tkinter.so ${PYTHONSCRIPTDIR}/site-packages

.include <bsd.port.mk>
