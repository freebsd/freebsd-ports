# New ports collection makefile for:	py-gtkscintilla
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-gtkscintilla
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moleskine
DISTNAME=	PyGtkScintilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python bindings for gtkscintilla library

LIB_DEPENDS=	gtkscintilla.0:${PORTSDIR}/x11-toolkits/gtkscintilla

USE_PYTHON=	yes
USE_GNOME=	gtk12
MAKE_ENV=	PYTHON_INCLUDE="${PYTHON_INCLUDEDIR}"

INST_DIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	${MKDIR} ${INST_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/_gtkscintillamodule.so ${INST_DIR}
.for file in gtkscintilla.py GTKSCINTILLA.py
	${INSTALL_DATA} ${WRKSRC}/${file} ${WRKSRC}/${file}c ${INST_DIR}
.endfor

.include <bsd.port.mk>
