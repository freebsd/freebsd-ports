# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyQt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	eugos@gmx.net
COMMENT=	Python bindings for the Qt toolkit

LIB_DEPENDS=	qscintilla.3:${PORTSDIR}/x11-toolkits/qscintilla
BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_QT_VER=	3
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OPENGL)
PLIST_SUB+=	GL="@comment "
.else
PLIST_SUB+=	GL=""
.endif

do-configure:
	@(cd ${WRKSRC} && ${ECHO} "yes" | ${PYTHON_CMD} configure.py \
		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-n ${X11BASE}/include -o ${X11BASE}/lib \
		-v ${PREFIX}/share/sip)

.include <bsd.port.post.mk>
